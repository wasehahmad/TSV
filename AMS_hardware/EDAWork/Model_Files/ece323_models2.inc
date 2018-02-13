* ECE323 VCO/PLL special model library edition

.subckt 74AC00 O A1 B1 vcc rtn
m0 O A1 vcc vcc pmos_1 w=20u l=1.6u
+ ad=96p pd=49.6u as=154.88p ps=105.6u 
m1 vcc B1 O vcc pmos_1 w=20u l=1.6u
+ ad=0p pd=0u as=0p ps=0u 
m2 a_13_3# A1 rtn rtn nmos_1 w=16.8u l=1.6u
+ ad=26.88p pd=36.8u as=67.2p ps=41.6u 
m3 O B1 a_13_3# rtn nmos_1 w=16.8u l=1.6u
+ ad=50.56p pd=41.6u as=0p ps=0u 
C0 vcc rtn 3.5fF
C1 vcc B1 2.2fF
C2 vcc A1 2.3fF
C3 A1 rtn 2.4fF
C4 O rtn 6.1fF
C5 B1 rtn 4.4fF
C6 A1 rtn 4.8fF
C7 vcc rtn 53.5fF
.ends 74AC00


.subckt CD4007_P d g s b
m1 d g s b pmos_1 w=1000u l=12u
.ends CD4007_P

.subckt CD4007_N d g s b
m1 d g s b nmos_1 w=1000u l=12u
.ends CD4007_N


**** MOS Models

* T1CI SPICE LEVEL3 PARAMETERS
*                                                                               
* DATE: Feb 11/02                                                               
* LOT: T1CI                  WAF: 7203                                          
* DIE: N_Area_Fring          DEV: N3740/10                                      
* Temp= 27                                                                      
.MODEL Nmos_1 NMOS (                                 LEVEL  = 3                  
+ TOX    = 3.07E-8         NSUB   = 1.193197E16     GAMMA  = 0.7332181          
+ PHI    = 0.7             VTO    = 0.6106854       DELTA  = 0.7182342          
+ UO     = 601.9269801     ETA    = 9.998816E-4     THETA  = 0.070571           
+ KP     = 7.428765E-5     VMAX   = 1.894035E5      KAPPA  = 0.5                
+ RSH    = 0.08379         NFS    = 6.785188E11     TPG    = 1                  
+ XJ     = 3E-7            LD     = 5.698171E-12    WD     = 6.874538E-7        
+ CGDO   = 1.79E-10        CGSO   = 1.79E-10        CGBO   = 1E-10              
+ CJ     = 2.880268E-4     PB     = 0.905851        MJ     = 0.5                
+ CJSW   = 1.233954E-10    MJSW   = 0.05            )                           
*                                                                               
*                                                                               
* DATE: Feb 11/02                                                               
* LOT: T1CI                  WAF: 7203                                          
* DIE: P_Area_Fring          DEV: P3740/10                                      
* Temp= 27                                                                      
.MODEL Pmos_1 PMOS (                                 LEVEL  = 3                  
+ TOX    = 3.07E-8         NSUB   = 1E17            GAMMA  = 0.4801562          
+ PHI    = 0.7             VTO    = -0.8727748      DELTA  = 0.4180493          
+ UO     = 102.7119278     ETA    = 0.5             THETA  = 0.1315069          
+ KP     = 2.434199E-5     VMAX   = 4.111656E5      KAPPA  = 100                
+ RSH    = 34.9751774      NFS    = 4.868265E11     TPG    = -1                 
+ XJ     = 2E-7            LD     = 6.937406E-14    WD     = 1E-6               
+ CGDO   = 2.18E-10        CGSO   = 2.18E-10        CGBO   = 1E-10              
+ CJ     = 2.914778E-4     PB     = 0.7457159       MJ     = 0.4262351          
+ CJSW   = 1.613212E-10    MJSW   = 0.1035851       )                           
*                      

*  End MOS Models


*-----------------------------------------------------------------------------
* connections:   non-inverting input
*                | inverting input
*                | | positive power supply
*                | | | negative power supply
*                | | | | open collector output
*                | | | | |
.subckt LM2901    1 2 3 4 5
*
  f1    9  3 v1 1
  iee   3  7 dc 100.0E-6
  vi1  21  1 dc .75
  vi2  22  2 dc .75
  q1    9 21  7 qin
  q2    8 22  7 qin
  q3    9  8  4 qmo
  q4    8  8  4 qmi
.model qin PNP(Is=800.0E-18 Bf=2.000E3)
.model qmi NPN(Is=800.0E-18 Bf=1002)
.model qmo NPN(Is=800.0E-18 Bf=1000 Cjc=1E-15 Tr=475.4E-9)
  e1   10  4  9  4  1
  v1   10 11 dc 0
  q5    5 11  4 qoc
.model qoc NPN(Is=800.0E-18 Bf=20.69E3 Cjc=1E-15 Tf=3.540E-9 Tr=472.8E-9)
  dp    4  3 dx
  rp    3  4 37.50E3
.model dx  D(Is=800.0E-18 Rs=1)
*
.ends
*$


*-------------------------------------------------------------------------------------------
*	Macromodeling of Integrated Circuit Operational Amplifiers
*	  by Graeme Boyle, Barry Cohn, Donald Pederson, and James Solomon
*	IEEE Journal of SoliE-State Circuits, Vol. SC-9, no. 6,	Dec. 1974
*
* Differences from the reference (above) occur in the output limiting stage
* which was modified to reduce internally generated currents associated with
* output voltage limiting, as well as short-circuit current limiting.
*
* The opamps are modelled at room temperature and do not track changes with
* temperature.  This library file contains models for nominal, not worst case,
* devices.
*
*
*-----------------------------------------------------------------------------
* connections:   non-inverting input
*                | inverting input
*                | | positive power supply
*                | | | negative power supply
*                | | | | output
*                | | | | |
.subckt LM324    1 2 3 4 5
*
  c1   11 12 2.887E-12
  c2    6  7 30.00E-12
  dc    5 53 dx
  de   54  5 dx
  dlp  90 91 dx
  dln  92 90 dx
  dp    4  3 dx
  egnd 99  0 poly(2) (3,0) (4,0) 0 .5 .5
  fb    7 99 poly(5) vb vc ve vlp vln 0 21.22E6 -20E6 20E6 20E6 -20E6
  ga    6  0 11 12 188.5E-6
  gcm   0  6 10 99 59.61E-9
  iee   3 10 dc 15.09E-6
  hlim 90  0 vlim 1K
  q1   11  2 13 qx
  q2   12  1 14 qx
  r2    6  9 100.0E3
  rc1   4 11 5.305E3
  rc2   4 12 5.305E3
  re1  13 10 1.845E3
  re2  14 10 1.845E3
  ree  10 99 13.25E6
  ro1   8  5 50
  ro2   7 99 25
  rp    3  4 9.082E3
  vb    9  0 dc 0
  vc    3 53 dc 1.500
  ve   54  4 dc 0.65
  vlim  7  8 dc 0
  vlp  91  0 dc 40
  vln   0 92 dc 40
.model dx D(Is=800.0E-18 Rs=1)
.model qx PNP(Is=800.0E-18 Bf=166.7)
.ends
*
*-------------------------------------------------------------------------------------------





*  ZETEX  ZVN3306A Mosfet Spice Subcircuit   Last revision  3/5/00
*
.SUBCKT ZVN3306A 3 4 5
*                D G S
M1 3 2 5 5 N3306M
RG 4 2 270
RL 3 5 1.2E8
C1 2 5 28E-12
C2 3 2 3E-12 
D1 5 3 N3306D
*
.MODEL N3306M NMOS VTO=1.824 RS=1.572 RD=1.436 IS=1E-15 KP=.1233
+CBD=35E-12 PB=1
.MODEL N3306D D IS=5E-12 RS=.768
.ENDS ZVN3306A   


*BS170 Model

.SUBCKT BS170 20 10 30 
*20=DRAIN 10=GATE 30=SOURCE 
vtemp 50 0 300
rtemp300 50 0 1Meg
Rg 10 11x 1
Rdu 12x 1 1u
M1 2 1 4x 4x DMOS L=1u W=1u
.MODEL DMOS NMOS(VTO=2.3 KP=8.5E-1
+THETA=0.05 VMAX=0.5E5 LEVEL=3)
Cgs 1 5x 27p
Rd 20 4 4E-1 
Dds 5x 4 DDS
.MODEL DDS D(M=4.72E+2 VJ=4.74E+3 CJO=27p)
Dbody 5x 20 DBODY
.MODEL DBODY D(IS=1.94E-12 N=1.201763 RS=0.00355 TT=43.65n)
Ra 4 2 4E-1 
Rs 5x 5 0.5m
Ls 5 30 0.5n
M2 1 8 6 6 INTER
E2 8 6 4 1 2
.MODEL INTER NMOS(VTO=0 KP=10 LEVEL=1)
Cgdmax 7 4 58p
Rcgd 7 4 10meg
Dgd 6 4 DGD
Rdgd 6 4 10meg
.MODEL DGD D(M=1E+3 VJ=4.74E+3 CJO=58p)
M3 7 9 1 1 INTER
E3 9 1 4 1 -2
*ZX SECTION
EOUT 4x 6x poly(2) (1x,0) (3x,0) 0 0 0 0 1
FCOPY 0 3x VSENSE 1
RIN 1x 0 1G
VSENSE 6x 5x 0
RREF 3x 0 10m
*TEMP SECTION
ED 101 0 VALUE {V(50,100)}
VAMB 100 0 25
ramb1 100 0 1Meg
EKP 1x 0 101 0 .82
*VTO TEMP SECTION
EVTO 102 0 101 0 .005
EVT 12x 11x 102 0 1
*DIODE THEMO BREAKDOWN SECTION
EBL VB1 VB2 101 0 .08
VBLK VB2 0 60
D 20 DB1 DBLK
.MODEL DBLK D(IS=1E-14 CJO=.1p RS=.1)
EDB DB1 0 VB1 0 1
.ENDS BS170
*BS170 (Rev.A) 3/22/02 **ST
                                     
*ZETEX  ZVP3306A Mosfet Spice Subcircuit     Last revision 3/5/00
*
.SUBCKT ZVP3306A     3 4 5
*                    D G S
M1 3 2 5 5 P3306M
RG 4 2 252
RL 3 5 1.2E8
C1 2 5 28E-12
C2 3 2 3E-12
D1 3 5 P3306D
*
.MODEL P3306M PMOS VTO=-2.875 RS=5.227 RD=7.524 IS=1E-15 KP=.145
+CBD=35E-12 PB=1 LAMBDA=6.67E-3
.MODEL P3306D D IS=5E-12 RS=.768
.ENDS 
*
*$

*$
.model D1N4148  D(Is=2.682n N=1.836 Rs=.5664 Ikf=44.17m Xti=3 Eg=1.11 Cjo=4p
+               M=.3333 Vj=.5 Fc=.5 Isr=1.565n Nr=2 Bv=100 Ibv=100u Tt=11.54n)
*$

.subckt lm317 out adj in tab
rx out tab .001
e1 x 0 out adj 1
e2 out 0 ref x 10000
vref ref 0 1.25
i50u in adj 50u
.ends lm317

* REF02 SPICE MACROMODEL                     9/91, Rev. A
*                                            (JCB / PMI)
*
* Copyright 1991 by Analog Devices, Inc.
*
* Refer to "README.DOC" file for License Statement.  Use of this model
* indicates your acceptance with the terms and provisions in the License 
* Statement.
*
*  N   ODE NUMBERS
*               T VIN
*                  |  GND
*                  |  |  TRIM
*                  |  |  |  VOUT
*                  |  |  |  |
.SUBCKT REF02   3  2  4  5  6
*
* 1.23V REFERENCE
*
I1     4  10   1.22889E-6
R1     10  4   1000E3  TC=3E-6
G1     4  10   21  4  1E-6
F1     4  10   VS  61.5E-9
*
* LINE REGULATION ZERO
*
E1     20  4   2  4  73.8
R11    20 21   1E6
R12    21  4   1
C4     20 21   27E-8
*
* INTERNAL OP AMP
*
G2     4  11   10  19  2E-3
R2     4  11   150E6
C1     4  11   2.6E-10
D1     11 12   DX
V1     2  12   1.3
*
* SECONDARY POLE
*
G3     4  13   11  0  1E-6
R3     4  13   1E6
C2     4  13   2.4E-13
*
* OUTPUT STAGE
*
ISY    2   4   0.385E-3
FSY    2   4   V1  -1
G4     4  14   13  0  25E-6
R4     4  14   40E3
R7     17 19   6.13008E3
R8     19  4   2E3
R9     19  5   25E3
R10    5   4   1E12
Q1     16 14   17   QN
VS     18 17   DC 0
L1     18  6   1E-7
*
* OUTPUT CURRENT LIMIT
*
Q2     15  2   16  QN
R6     2  16   19
R5     2  15   18E3
C3     2  15   1E-6
G5     14  4   2  15  1
*
.MODEL  QN  NPN(IS=1E-15  BF=1000)
.MODEL  DX  D(IS=1E-18)
.ENDS


.SUBCKT MCP6021 1 2 3 4 5
*               | | | | |
*               | | | | Output
*               | | | Negative Supply
*               | | Positive Supply
*               | Inverting Input
*               Non-inverting Input
*
********************************************************************************
* Software License Agreement                                                   *
*                                                                              *
* The software supplied herewith by Microchip Technology Incorporated (the     *
* 'Company') is intended and supplied to you, the Company's customer, for use  *
* soley and exclusively on Microchip products.                                 *
*                                                                              *
* The software is owned by the Company and/or its supplier, and is protected   *
* under applicable copyright laws. All rights are reserved. Any use in         *
* violation of the foregoing restrictions may subject the user to criminal     *
* sanctions under applicable laws, as well as to civil liability for the       *
* breach of the terms and conditions of this license.                          *
*                                                                              *
* THIS SOFTWARE IS PROVIDED IN AN 'AS IS' CONDITION. NO WARRANTIES, WHETHER    *
* EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED        *
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO  *
* THIS SOFTWARE. THE COMPANY SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR    *
* SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.     *
********************************************************************************
*
* The following op-amps are covered by this model:
*      MCP6021,MCP6021R,MCP6022,MCP6023,MCP6024
*
* Revision History:
*     REV A: 10-Feb-01, KEB (created model)
*     REV B: 27-Aug-06, HNV (added over temperature, improved output stage, 
*                            fixed overdrive recovery time)
*			    (MC_RQ, 27-Aug-06, Level 1.17)       
*
* Recommendations:
*      Use PSPICE (other simulators may require translation)
*      For a quick, effective design, use a combination of: data sheet
*            specs, bench testing, and simulations with this macromodel
*      For high impedance circuits, set GMIN=100F in the .OPTIONS statement
*
* Supported:
*      Typical performance for temperature range (-40 to 125) degrees Celsius
*      DC, AC, Transient, and Noise analyses.
*      Most specs, including: offsets, DC PSRR, DC CMRR, input impedance,
*            open loop gain, voltage ranges, supply current, ... , etc.
*      Temperature effects for Ibias, Iquiescent, Iout short circuit 
*            current, Vsat on both rails, Slew Rate vs. Temp and P.S.
*
* Not Supported:
*      Chip select (MCP6023)
*      Some Variation in specs vs. Power Supply Voltage
*      Monte Carlo (Vos, Ib), Process variation
*      Distortion (detailed non-linear behavior)
*      Behavior outside normal operating region
*
* Input Stage
V10  3 10 -500M
R10 10 11 690K
R11 10 12 690K
G10 10 11 10 11 288U
G11 10 12 10 12 288U
C11 11 12 0.2P
C12  1  0 6.00P
E12 71 14 POLY(4) 20 0 21 0 26 0 27 0   0 1 1 1 1
G12 1 0 62 0 1m
M12 11 14 15 15 NMI
G13 1 2 62 0 .08m 
M14 12 2 15 15 NMI 
G14 2 0 62 0 1m
C14  2  0 6.00P
I15 15 4 225.0U
V16 16 4 -300M
GD16 16 1 TABLE {V(16,1)} ((-100,-1p)(0,0)(1m,1u)(2m,1m)) 
V13 3 13 -300M
GD13 2 13 TABLE {V(2,13)} ((-100,-1p)(0,0)(1m,1u)(2m,1m)) 
R71  1  0 20.0E12
R72  2  0 20.0E12
R73  1  2 20.0E12
I80  1  2 500E-15
*
* Noise, PSRR, and CMRR
I20 21 20 423U
D20 20  0 DN1
D21  0 21 DN1
G26  0 26 POLY(2) 3 0 4 0   0.00 -31.6U -79.4U
R26 26  0 1
E271 275 0 1 0 1
E272 276 0 2 0 1
R271 275 271 37k
R272 276 272 37k
R273 271 0 1k
R274 272 0 1k
C271 275 271 3p
C272 276 272 3p
G27  0 27 POLY(2) 271 0 272 0  -327U 500U 500U
R27 27  0 1
*
* Open Loop Gain, Slew Rate
G30  0 30 12 11 1
R30 30  0 1.00K
G31 0 31 3 4 4
I31 0 31 DC 76.9
R31 31  0 1 TC=2.34M,-4.57U
GD31 30 0 TABLE {V(30,31)} ((-100,-1n)(0,0)(1m,0.1)(2m,2))
G32 32 0 3 4 10
I32 32 0 DC 65
R32 32  0 1 TC=1.80M,-3.97U
GD32 0 30 TABLE {V(30,32)} ((-2m,2)(-1m,0.1)(0,0)(100,-1n))
G33  0 33 30 0 1m
R33  33 0 1K
G34  0 34 33 0 1.00
R34  34 0 1K
C34  34 0 14U
G37  0 37 34 0 1m
R37  37 0 1K
C37  37 0 6P
G38  0 38 37 0 1m
R38  39 0 1K
L38  38 39 31U
E38  35 0 38 0 1
G35 33 0 TABLE {V(35,3)} ((-1,-1n)(0,0)(50.0,1n))(55.0,1))
G36 33 0 TABLE {V(35,4)} ((-55.0,-1)((-50.0,-1n)(0,0)(1,1n))
*
* Output Stage
R80 50 0 100MEG
G50 0 50 57 96 2
R58 57  96 0.50
R57 57  0 500
C58  5  0 2.00P
G57  0 57 POLY(3) 3 0 4 0 35 0   0 0.75M 0.8M 2.00M
GD55 55 57 TABLE {V(55,57)} ((-2m,-1)(-1m,-1m)(0,0)(10,1n))
GD56 57 56 TABLE {V(57,56)} ((-2m,-1)(-1m,-1m)(0,0)(10,1n))
E55 55  0 POLY(2) 3 0 51 0 -1.4M 1 -19.1M
E56 56  0 POLY(2) 4 0 52 0 3.5M 1 -19.0M
R51 51 0 1k
R52 52 0 1k
GD51 50 51 TABLE {V(50,51)} ((-10,-1n)(0,0)(1m,1m)(2m,1))
GD52 50 52 TABLE {V(50,52)}  ((-2m,-1)(-1m,-1m)(0,0)(10,1n))
G53  3  0 POLY(1) 51 0  -50.0U 1M
G54  0  4 POLY(1) 52 0  -50.0U -1M
*
* Current Limit
G99 96 5 99 0 1
R98 0 98 1 TC=3.18M,-842N
G97 0 98 TABLE { V(96,5) } ((-11.0,-23.0M)(-1.00M,-22.7M)(0,0)(1.00M,22.7M)(11.0,23.0M))
E97 99 0 VALUE { V(98)*((V(3)-V(4))*0.00 + 1.00)}
D98 4 5 DESD
D99 5 3 DESD
*
* Temperature / Voltage Sensitive IQuiscent
R61 0 61 1 TC=2.62M,-1.92U
G61 3 4 61 0 1
G60 0 61 TABLE {V(3, 4)} 
+ ((0,0)(900M,9.2U)(1.1,50U)(1.3,240U)
+ (2.1,870U)(2.2,900U)(5.5,980U))
*
* Temperature Sensistive offset voltage
I73 0 70 DC 1uA
R74 0 70 1 TC=3.5
E75 1 71 70 0 1 
*
* Temp Sensistive IBias
I62 0 62 DC 1uA
R62 0 62 REXP  245U
*
* Models
.MODEL NMI NMOS(L=2.00U W=42.0U KP=20.0U LEVEL=1 )
.MODEL DESD  D   N=1 IS=1.00E-15
.MODEL DN1 D   IS=1P KF=12.5F AF=1
.MODEL REXP RES TCE= 9.16
.ENDS MCP6021



.SUBCKT MCP6241 1 2 3 4 5
*               | | | | |
*               | | | | Output
*               | | | Negative Supply
*               | | Positive Supply
*               | Inverting Input
*               Non-inverting Input
*
********************************************************************************
* Software License Agreement                                                   *
*                                                                              *
* The software supplied herewith by Microchip Technology Incorporated (the     *
* 'Company') is intended and supplied to you, the Company's customer, for use  *
* soley and exclusively on Microchip products.                                 *
*                                                                              *
* The software is owned by the Company and/or its supplier, and is protected   *
* under applicable copyright laws. All rights are reserved. Any use in         *
* violation of the foregoing restrictions may subject the user to criminal     *
* sanctions under applicable laws, as well as to civil liability for the       *
* breach of the terms and conditions of this license.                          *
*                                                                              *
* THIS SOFTWARE IS PROVIDED IN AN 'AS IS' CONDITION. NO WARRANTIES, WHETHER    *
* EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED        *
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO  *
* THIS SOFTWARE. THE COMPANY SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR    *
* SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.     *
********************************************************************************
*
* The following op-amps are covered by this model:
*      MCP6241,MCP6242,MCP6244
*
* Revision History:
*      REV A: 21-Aug-06, Created model 
*      REV B: 27-Jul-07, Updated output impedance for better model stability w/cap load
*       
* Recommendations:
*      Use PSPICE (other simulators may require translation)
*      For a quick, effective design, use a combination of: data sheet
*            specs, bench testing, and simulations with this macromodel
*      For high impedance circuits, set GMIN=100F in the .OPTIONS statement
*
* Supported:
*      Typical performance for temperature range (-40 to 125) degrees Celsius
*      DC, AC, Transient, and Noise analyses.
*      Most specs, including: offsets, DC PSRR, DC CMRR, input impedance,
*            open loop gain, voltage ranges, supply current, ... , etc.
*      Temperature effects for Ibias, Iquiescent, Iout short circuit 
*            current, Vsat on both rails, Slew Rate vs. Temp and P.S.
*
* Not Supported:
*      Some Variation in specs vs. Power Supply Voltage
*      Monte Carlo (Vos, Ib), Process variation 
*      Distortion (detailed non-linear behavior)
*      Behavior outside normal operating region
*
* Input Stage
V10  3 10 -500M
R10 10 11 6.90K
R11 10 12 6.90K
C11 11 12 7.20P
C12  1  0 6.00P
E12 71 14 POLY(4) 20 0 21 0 26 0 27 0   5.00M 34.9 34.9 1 1
G12 1 0 62 0 1m
M12 11 14 15 15 NMI 
M14 12 2 15 15 NMI 
G14 2 0 62 0 1m
C14  2  0 6.00P
I15 15 4 50.0U
V16 16 4 -300M
GD16 16 1 TABLE {V(16,1)} ((-100,-1p)(0,0)(1m,1u)(2m,1m)) 
V13 3 13 -300M
GD13 2 13 TABLE {V(2,13)} ((-100,-1p)(0,0)(1m,1u)(2m,1m)) 
R71  1  0 20.0E12
R72  2  0 20.0E12
R73  1  2 20.0E12
I80  1  2 500E-15
*
* Noise, PSRR, and CMRR
I20 21 20 423U
D20 20  0 DN1
D21  0 21 DN1
G26  0 26 POLY(2) 3 0 4 0   0.00 -158U -3U
R26 26  0 1
G27  0 27 POLY(2) 1 0 2 0  -776U 35.5U 35.5U
R27 27  0 1
*
* Open Loop Gain, Slew Rate
G30  0 30 12 11 1
R30 30  0 1.00K
C30 30 0 10p
G31 0 31 3 4 2
I31 0 31 DC 65
R31 31  0 1 TC=3.67M,5.32U
GD31 30 0 TABLE {V(30,31)} ((-100,-1u)(0,0)(1m,.1)(2m,2))
G32 32 0 3 4 -1.9
I32 32 0 DC 105
R32 32  0 1 TC=3.43M,4.42U
GD32 0 30 TABLE {V(30,32)} ((-2m,2)(-1m,.1)(0,0)(100,1u))
G33  0 33 30 0 1m
R33  33 0 1K
G34  0 34 33 0 316M
R34  34 0 1K
C34  34 0 81.8U
G37  0 37 34 0 1m
R37  37 0 1K
C37  37 0 22.7P
G38  0 38 37 0 1m
R38  39 0 1K
L38  38 39 26.5U
E38  35 0 38 0 1
G35 33 0 TABLE {V(35,3)} ((-1,-1n)(0,0)(48,1n))(49,1))
G36 33 0 TABLE {V(35,4)} ((-49,-1)((-48,-1n)(0,0)(1,1n))
*
* Output Stage
R80 50 0 100MEG
G50 0 50 57 96 2
R58 57  96 0.50
R57 57  0 1650
C58  5  0 2.00P
G57  0 57 POLY(3) 3 0 4 0 35 0   0 0.21M 0.21M 0.6M
GD55 55 57 TABLE {V(55,57)} ((-2m,-1)(-1m,-1m)(0,0)(10,1n))
GD56 57 56 TABLE {V(57,56)} ((-2m,-1)(-1m,-1m)(0,0)(10,1n))
E55 55  0 POLY(2) 3 0 51 0 -0.85M 1 -51.0M
E56 56  0 POLY(2) 4 0 52 0 1.33M 1 -42.0M
R51 51 0 1k
R52 52 0 1k
GD51 50 51 TABLE {V(50,51)} ((-10,-1n)(0,0)(1m,1m)(2m,1))
GD52 50 52 TABLE {V(50,52)}  ((-2m,-1)(-1m,-1m)(0,0)(10,1n))
G53  3  0 POLY(1) 51 0  -50.0U 1M
G54  0  4 POLY(1) 52 0  -50.0U -1M
*
* Current Limit
G99 96 5 99 0 1
R98 0 98 1 TC=-1.92M,-7.58U
G97 0 98 TABLE { V(96,5) } ((-11.0,-21.0M)(-1.00M,-20.7M)(0,0)(1.00M,20.7M)(11.0,21.0M))
E97 99 0 VALUE { V(98)*((V(3)-V(4))*166M + 416M)}
D98 4 5 DESD
D99 5 3 DESD
*
* Temperature / Voltage Sensitive IQuiscent
R61 0 61 1 TC=3.14M,7.28U
G61 3 4 61 0 1
G60 0 61 TABLE {V(3, 4)} 
+ ((0,0)(750M,450N)(800M,1.00U)(900M,4.00U)
+ (1.2,41.0U)(1.4,45.0U)(5.5,46.0U))
*
* Temperature Sensistive offset voltage
I73 0 70 DC 1uA
R74 0 70 1 TC=3.00U
E75 1 71 70 0 1 
*
* Temp Sensistive IBias
I62 0 62 DC 1uA
R62 0 62 REXP 55.78U
*
* Models
.MODEL NMI NMOS(L=2.00U W=42.0U KP=20.0U LEVEL=1 )
.MODEL DESD  D   N=1 IS=1.00E-15
.MODEL DN1 D   IS=1P KF=146E-18 AF=1
.MODEL REXP RES TCE=10.14
.ENDS MCP6241



* connections:   non-inverting input

*                | inverting input

*                | | positive power supply

*                | | | negative power supply

*                | | | | output

*                | | | | |

.SUBCKT OPA134   1 2 3 4 5

*

C1   11 12 3.240E-12

C2    6  7 8.000E-12

CSS  10 99 1.000E-30

DC    5 53 DX

DE   54  5 DX

DLP  90 91 DX

DLN  92 90 DX

DP    4  3 DX

EGND 99  0 POLY(2) (3,0) (4,0) 0 .5 .5

FB    7 99 POLY(5) VB VC VE VLP VLN 0 248.0E6 -250E6 250E6 250E6 -250E6

GA    6  0 11 12 402.0E-6

GCM   0  6 10 99 4.020E-9

ISS   3 10 DC 160.0E-6

HLIM 90  0 VLIM 1E3

J1   11  2 10 JX

J2   12  1 10 JX

R2    6  9 100.0E3

RD1   4 11 2.490E3

RD2   4 12 2.490E3

RO1   8  5 20

RO2   7 99 20

RP    3  4 7.500E3

RSS  10 99 1.250E6

VB    9  0 DC 0

VC    3 53 DC 1.200

VE   54  4 DC .9

VLIM  7  8 DC 0

VLP  91  0 DC 40

VLN   0 92 DC 40

.MODEL DX D(IS=800.0E-18)

.MODEL JX PJF(IS=2.500E-15 BETA=1.010E-3 VTO=-1)

.ENDS


*DEVICE=OPA137,OPAMP,PJF,INT

* OPA137 operational amplifier "macromodel" subcircuit
* created using Parts release 8.0 on 10/21/104 at 10:40
* by Neil P. Albaugh
* Parts is a MicroSim product.
*
* connections:   non-inverting input
*                | inverting input
*                | | positive power supply
*                | | | negative power supply
*                | | | | output
*                | | | | |
.subckt OPA137   1 2 3 4 5
*
  c1   11 12 1.6246E-12
  c2    6  7 10.000E-12
  css  10 99 1.0000E-30
  dc    5 53 dy
  de   54  5 dy
  dlp  90 91 dx
  dln  92 90 dx
  dp    4  3 dx
  egnd 99  0 poly(2) (3,0) (4,0) 0 .5 .5
  fb    7 99 poly(5) vb vc ve vlp vln 0 31.831E6 -1E3 1E3 32E6 -32E6
  ga    6  0 11 12 62.832E-6
  gcm   0  6 10 99 3.1416E-9
  iss   3 10 dc 35.000E-6
  hlim 90  0 vlim 1K
  j1   11  2 10 jx1
  j2   12  1 10 jx2
  r2    6  9 100.00E3
  rd1   4 11 15.915E3
  rd2   4 12 15.915E3
  ro1   8  5 50
  ro2   7 99 25
  rp    3  4 14.851E3
  rss  10 99 5.7143E6
  vb    9  0 dc 0
  vc    3 53 dc 1.9037
  ve   54  4 dc 2.0037
  vlim  7  8 dc 0
  vlp  91  0 dc 25
  vln   0 92 dc 25
.model dx D(Is=800.00E-18)
.model dy D(Is=800.00E-18 Rs=1m Cjo=10p)
.model jx1 PJF(Is=2.5000E-12 Beta=112.80E-6 Vto=-1)
.model jx2 PJF(Is=2.5000E-12 Beta=112.80E-6 Vto=-1)
.ends
*$

* TL3474 OPERATIONAL AMPLIFIER "MACROMODEL" SUBCIRCUIT

* connections:   non-inverting input
*                | inverting input
*                | | positive power supply
*                | | | negative power supply
*                | | | | output
*                | | | | |
.subckt TL3474   1 2 3 4 5
*
  c1   11 12 4.5496E-12
  c2    6  7 25.000E-12
  cee  10 99 9.0000E-12
  dc    5 53 dy
  de   54  5 dy
  dlp  90 91 dx
  dln  92 90 dx
  dp    4  3 dx
  egnd 99  0 poly(2) (3,0) (4,0) 0 .5 .5
  fb    7 99 poly(5) vb vc ve vlp vln 0 6.3662E6 -1E3 1E3 6E6 -6E6
  ga    6  0 11 12 942.48E-6
  gcm   0  6 10 99 9.4248E-9
  iee   3 10 dc 39.194E-6
  hlim 90  0 vlim 1K
  q1   11  2 13 qx1
  q2   12  1 14 qx2
  r2    6  9 100.00E3
  rc1   4 11 1.0610E3
  rc2   4 12 1.0610E3
  re1  13 10 .1
  re2  14 10 .1
  ree  10 99 5.1028E6
  ro1   8  5 50
  ro2   7 99 25
  rp    3  4 109.87E3
  vb    9  0 dc 0
  vc    3 53 dc 1.8066
  ve   54  4 dc 1.8066
  vlim  7  8 dc 0
  vlp  91  0 dc 28
  vln   0 92 dc 28
.model dx D(Is=800.00E-18)
.model dy D(Is=800.00E-18 Rs=1m Cjo=10p)
.model qx1 PNP(Is=800.00E-18 Bf=201.03)
.model qx2 PNP(Is=831.5365E-18 Bf=201.03)
.ends

*** DIP Level Models

.SUBCKT 74AC00DIP 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
XNAND1 3  1   2  14 7 74AC00
XNAND2 6  4   5  14 7 74AC00
XNAND3 8  9  10  14 7 74AC00
XNAND4 11 12 13  14 7 74AC00
.ENDS

.SUBCKT LM324DIP 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
XAMP1  3  2 4 11 1  LM324
XAMP2  5  6 4 11 7  LM324
XAMP3 10  9 4 11 8  LM324
XAMP4 12 13 4 11 14 LM324
.ENDS

.SUBCKT LM2901DIP 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
XCMP1  5  4 3 12 2  LM2901
XCMP2  7  6 3 12 1  LM2901
XCMP3  9  8 3 12 14 LM2901
XCMP4 11 10 3 12 13 LM2901
.ENDS

.SUBCKT CD4007UBDIP 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
XFET1 13  6 14 14 CD4007_P 
XFET2  1  3  2 14 CD4007_P 
XFET3 12 10 11 14 CD4007_P 
XFET4  8  6  7  7 CD4007_N 
XFET5  5  3  4  7 CD4007_N 
XFET6  12 10 9  7 CD4007_N 
.ends

.SUBCKT MCP6024DIP 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
XAMP1  3  2 4 11 1  MCP6021
XAMP2  5  6 4 11 7  MCP6021
XAMP3 10  9 4 11 8  MCP6021
XAMP4 12 13 4 11 14 MCP6021
.ENDS

.SUBCKT MCP6244DIP 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
XAMP1  3  2 4 11 1  MCP6241
XAMP2  5  6 4 11 7  MCP6241
XAMP3 10  9 4 11 8  MCP6241
XAMP4 12 13 4 11 14 MCP6241
.ENDS

.SUBCKT MCP6242DIP 1 2 3 4 5 6 7 8  
XAMP1  3 2 8 4 1  MCP6241
XAMP2  5 6 8 4 7  MCP6241
.ENDS

.SUBCKT OPA2134DIP 1 2 3 4 5 6 7 8  
XAMP1  3 2 8 4 1  OPA134
XAMP2  5 6 8 4 7  OPA134
.ENDS

.SUBCKT OPA4137DIP 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
XAMP1  3  2 4 11 1  OPA137
XAMP2  5  6 4 11 7  OPA137
XAMP3 10  9 4 11 8  OPA137
XAMP4 12 13 4 11 14 OPA137
.ENDS

.SUBCKT tl3474DIP 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
XAMP1  3  2 4 11 1  tl3474
XAMP2  5  6 4 11 7  tl3474
XAMP3 10  9 4 11 8  tl3474
XAMP4 12 13 4 11 14 tl3474
.ENDS


* ALD4201 and 4202 spice models

.subckt ald4201dip in1 d1 s1 vnn vgnd s4 d4 in4 in3 d3 s3 nc vcc s2 d2 in2
switch1 d1 s1 in1 vgnd vswitch1
switch2 d2 s2 in2 vgnd vswitch1
switch3 d3 s3 in3 vgnd vswitch1
switch4 d4 s4 in4 vgnd vswitch1 
.model vswitch1 sw (VT=2.5 VH=.01 RON=16Meg ROFF=100)
.ends ald4201dip

.subckt ald4202dip in1 d1 s1 vnn vgnd s4 d4 in4 in3 d3 s3 nc vcc s2 d2 in2
switch1 d1 s1 in1 vgnd vswitch1
switch2 d2 s2 in2 vgnd vswitch1
switch3 d3 s3 in3 vgnd vswitch1
switch4 d4 s4 in4 vgnd vswitch1 
.model vswitch1 sw (VT=2.5 VH=.01 RON=100 ROFF=16Meg)
.ends ald4202dip

*---LM319cell--------------------------------------------------------------------------
            * connections: non-inverting input
            * | inverting input
            * | | positive power supply
            * | | | negative power supply
            * | | | | open collector output
            * | | | | | ground
            * | | | | | |
.subckt LM319 1 2 3 4 5 6
*
f1 3 9 v1 1
iee 7 4 dc 100.0E-6
q1 9 2 7 qin
q2 8 1 7 qin
q3 9 8 3 qmo
q4 8 8 3 qmi
.model qin NPN(Is=800.0E-18 Bf=333.3)
.model qmi PNP(Is=800.0E-18 Bf=1002)
.model qmo PNP(Is=800.0E-18 Bf=1000 Cjc=1E-15 Tr=59.42E-9)
e1 10 6 3 9 1
v1 10 11 dc 0
q5 5 11 6 qoc
.model qoc NPN(Is=800.0E-18 Bf=41.38E3 Cjc=1E-15 Tf=23.91E-12 Tr=24.01E-9)
dp 4 3 dx
rp 3 4 5.556E3
.model dx D(Is=800.0E-18 Rs=1)
*
.ends

.subckt LM319DIP 1 2 3 4 5 6 7 8 9 10 11 12 13 14
xcomp1 4 5 11 6 12 3 lm319
xcomp2 9 10 11 6 7 8 lm319
.ends lm319dip

.SUBCKT tip102 1 2 3
**************************************
*      Model Generated by MODPEX     *
*Copyright(c) Symmetry Design Systems*
*         All Rights Reserved        *
*    UNPUBLISHED LICENSED SOFTWARE   *
*   Contains Proprietary Information *
*      Which is The Property of      *
*     SYMMETRY OR ITS LICENSORS      *
*Commercial Use or Resale Restricted *
*   by Symmetry License Agreement    *
**************************************
* Model generated on Jan 20, 03
* MODEL FORMAT: PSpice
* Darlington macro model
* External node designations
* Node 1 -> Collect
* Node 2 -> Base
* Node 3 -> Emitter
Q1 1 2 4 qmodel
Q2 1 4 3 q1model 11.2198
D1 3 1 dmodel
R1 2 4 8000
R2 4 3 120
* Default values used in dmodel
*   EG=1.11 TT=0 BV=infinite
.MODEL dmodel d
+IS=1e-12 RS=10 N=1 XTI=3
+CJO=0 VJ=0.75 M=0.33 FC=0.5
.MODEL qmodel npn
+IS=2.88485e-13 BF=126.335 NF=1.2 VAF=30
+IKF=0.132527 ISE=6.51929e-12 NE=1.9601 BR=0.100001
+NR=1.5 VAR=300 IKR=0.0843484 ISC=1.01027e-13
+NC=1.92564 RB=2.61873 IRB=0.2 RBM=2.61873
+RE=0.0001 RC=2.60372 XTB=0 XTI=4 EG=1.206
+CJE=1.13087e-10 VJE=0.95 MJE=0.692676 TF=1e-09
+XTF=1 VTF=10 ITF=0.01 CJC=1.56651e-10
+VJC=0.908287 MJC=0.23 XCJC=0.897966 FC=0.5
+TR=1e-07 PTF=0 KF=0 AF=1
.MODEL q1model npn
+IS=2.88485e-13 BF=126.335 NF=1.2 VAF=30
+IKF=0.132527 ISE=6.51929e-12 NE=1.9601 BR=0.100001
+NR=1.5 VAR=300 IKR=0.0843484 ISC=1.01027e-13
+NC=1.92564 RB=2.61873 IRB=0.2 RBM=2.61873
+RE=0.0001 RC=2.60372 XTB=0 XTI=4 EG=1.206
+CJE=1.13087e-10 VJE=0.95 MJE=0.692676 TF=1e-09
+XTF=1 VTF=10 ITF=0.01 CJC=0
+VJC=0.908287 MJC=0.23 XCJC=0.897966 FC=0.5
+TR=1e-07 PTF=0 KF=0 AF=1
.ENDS tip102


*LED of some sort
.subckt LuxStar-1watt a c
* 06/2002 MrAl
d1 a c dx
RL a c 1Meg
.model dx d is=2e-17 n=3.40 RS=0.1 cjo=100p
.ends



              
