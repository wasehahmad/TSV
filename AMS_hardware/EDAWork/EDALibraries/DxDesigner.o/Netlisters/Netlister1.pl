##########################################################################
#  Netlisting file to convert from WVIEW DRC format to subcircuit format #
#    This netlister is AMI C5 specific                                   #
#                                                                        #
########################################################################## 
# Modified 10/27/01  Version AMI_C5_Subcircuit.1
# First read in the temporary spice file for conversion and define output file
  $CirFile = "tempfile.cir";
  $SubFile = "tempfile.sub";
  open(INFILE, $CirFile) or die "No .CIR found. \n";
  open(OUTFILE, ">$SubFile") or die "Crap";
#
# Now create embedded tech file to add parasitic device information 
# Create technology variable table
  $PGS            = 0.0    ;# P-gate Sizing
  $NGS            = 0.0    ;# N-gate Sizing
  $DDWIDTHCORE    = 1.3    ;# Drawn Diffusion Width with contacts. 
  $DDWIDTHPAD     = 7.2    ;# Drawn diffusion for pad devices
  $BASE_RHO       = -99.0  ;# Base Sheet Resistance
  $NPOLY_RHO      = 31     ;# N-Poly Sheet Resistance  (PO)
  $NPLUS_RHO      = 90     ;# N-Plus Sheet Resistance   (NP)
  $PPLUS_RHO      = 110    ;# P-Plus Sheet Resistance   (PP)
  $NWELL_RHO      = 850    ;# Nwell Field Sheet Resistance  (NW)
  $Poly_CAP       = 0.001  ;# MIM Capacitance (pF/um^2)               
  $SCALE_FACTOR   = 1.0    ;# Scale factor 
  $METAL1_RHO     = 0.076  ;# Interior Metal Sheet Resistance
  $METAL2_RHO     = 0.041  ;# Top Level Metal Sheet Resistance
#
# 
# Expected input formats for devices
#   M* D G S B MDL W= L= M= SD=' ' PAD=' '
#   R* 1 2 Rval MDL W= L= M= S/P=' '
#   C* 1 2 MDL Cval Area IC=
#   Q* C B E MDL Area M=

# Initialize Count Variables
  $countM=0;
  $countR=0; $errorcountR=0;
  $countC=0; $errorcountC=0;
  $countQ=0;

  # Modify the circuit file lines	
  while(<INFILE>) {
	$TheLine = $_; # Save current line's contents
	chomp($TheLine); # Removes line break

#   M* D G S B MDL W= L= M= SD=' ' PAD=' '
# Required Model Names:  P35=PCH, P50=PCH5V, N35=NCH, N50=NCH5V
# START TRANSISTORS
	   if(substr($TheLine, 0, 1) eq "M")   # Operate on Transistors
                {$countM=$countM+1; # Count Transistors
		@decomp = split(/ /, $TheLine);  # Create a vector from string for transistor manipulation
		
		# Rename Model if required (not used for Amis C5)
		# if($decomp[5] eq "P35") {$decomp[5]=PCH};
		# if($decomp[5] eq "P50") {$decomp[5]=PCH5V};
		# if($decomp[5] eq "N35") {$decomp[5]=NCH};
		# if($decomp[5] eq "N50") {$decomp[5]=NCH5V};

		$W = $decomp[6];  # Get W=xxx
		$W=reverse $W;  # Remove W= to leave only numeric portion
	        chop($W);
		chop($W);
		$W=reverse $W;
		
		
		# Check for pad cell
		$Drain=$decomp[10];
		chop($Drain);
		$Drain=reverse $Drain;
		chop($Drain);
		chop($Drain);
		chop($Drain);
		chop($Drain);
		chop($Drain);
		if ($Drain eq 'Y') {$DDWIDTH=$DDWIDTHPAD} else {$DDWIDTH=$DDWIDTHCORE};

		# Check for shared drains 
		$Share=$decomp[9];
		chop($Share);
		$Share=reverse $Share;
		chop($Share);
		chop($Share);
		chop($Share);
		chop($Share);
		if ($Share eq 'Y') {$SS=0.5} else {$SS=1};
		
		# Get multiplier information
		$Mult=$decomp[8];
		$Mult=reverse $Mult;  # Remove M= to leave only numeric portion
	        chop($Mult);
		chop($Mult);
		$Mult=reverse $Mult;
		
		# Calculate effective $W for shared drains including odd multiplier effect;
		if ($SS eq '0.5') {$Multtemp=$Mult/2, $Multtemp1=sprintf("%.0f", $Multtemp), $Multtemp2=2*($Multtemp-$Multtemp1)}
		 else {$Multtemp=$Mult, $Multtemp1=$Multtemp, $Multtemp2=0};
		$MCorr=($Multtemp1+$Multtemp2)/$Mult;  # Correction for odd number fingers for drain area calc
				
		$AD=$W*$DDWIDTH*$MCorr;  # Calculate Drain and Source Areas
		$AD=sprintf("%.3f", $AD);  # Round to 3rd Decimal
		$AS=$W*$DDWIDTHCORE*$MCorr; # Assume Source is core rule
		$AS=sprintf("%.3f", $AS);  # Round to 3rd Decimal


		$PD=2*($W+$DDWIDTH)*$MCorr;  # Calculate Drain and Souce Peripheries
		$PD=sprintf("%.3f", $PD);  # Round to 3rd Decimal
		$PS=2*($W+$DDWIDTHCORE)*$MCorr;
		$PS=sprintf("%.3f", $PS);  # Round to 3rd Decimal
		
		$NRD=$DDWIDTH/($W*$MCorr);  # Calculate Number of Squares in Drain and Source
		$NRD=sprintf("%.6f", $NRD);  # Round to 6th Decimal
		$NRS=$DDWIDTHCORE/($W*$MCorr);  
		$NRS=sprintf("%.6f", $NRS);  # Round to 6th Decimal
		
		$decomp[6]="$decomp[6]".'U';  # Append units to W and L
		$decomp[7]="$decomp[7]".'U';
		$decomp[9]=' ';
		$decomp[10]=' ';
		# splice(@decomp,10,0,("AD=$AD".'P',"AS=$AS".'P',"PD=$PD".'U',"PS=$PS".'U', "NRD=$NRD", "NRS=$NRS")); # Adds computations for areas and peripheries and units
		$TheLine1 = join(" ", @decomp); # reduces array to string
		$TheLine2 = join(" ", ("AD=$AD".'P',"AS=$AS".'P',"PD=$PD".'U',"PS=$PS".'U'));
		$TheLine3 = join(" ", ("NRD=$NRD", "NRS=$NRS"));
		$TheLine = " ";
		print "$TheLine1\n";
		print "+ $TheLine2\n";
		print "+ $TheLine3";
		print OUTFILE "$TheLine1\n";
		print OUTFILE "+ $TheLine2\n";
		print OUTFILE "+ $TheLine3"};
# END TRANSISTORS

# START RESISTORS
	if(substr($TheLine, 0, 1) eq "R")   # Operate on Resistors
		{$countR=$countR+1}; # Count Resistors
		
# END RESISTORS

# START CAPACITORS - C* 1 2 MDL CVAL AREA IC=
	if(substr($TheLine, 0, 1) eq "C")   # Operate on Capacitors
		{$countC=$countC+1}; # Count Caps
		
# END CAPACITORS

# START BIPOLARS - Q* C B E MDL AREA M=
	if(substr($TheLine, 0, 1) eq "Q")   # Operate on Bipolars
		{$countQ=$countQ+1}; # Count Bipolars
		
# END BIPOLARS

	print "$TheLine\n";
	print OUTFILE "$TheLine\n"};
	print "\nSummary of Found Components:\n";
	print "       $countQ Bipolars\n";
	print "       $countM Transistors\n";
	print "       $countR Resistors with $errorcountR errors\n";
	print "       $countC Capacitors with $errorcountC errors\n\n";

	
