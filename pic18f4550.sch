v 20130925 2
C 40000 40000 0 0 0 title-B.sym
C 45300 42400 1 0 0 PIC18F4550_DIP40.sym
{
T 50500 48900 5 10 1 1 0 6 1
refdes=U1
T 45700 49100 5 10 0 0 0 0 1
device=PIC18F4550_DIP40
T 45700 49300 5 10 0 0 0 0 1
footprint=DIP40
}
C 44200 41300 1 90 0 crystal-1.sym
{
T 43700 41500 5 10 0 0 90 0 1
device=CRYSTAL
T 43900 41500 5 10 1 1 90 0 1
refdes=U3
T 43500 41500 5 10 0 0 90 0 1
symversion=0.1
T 44200 41300 5 10 1 1 0 0 1
value=4 MHz
}
C 40100 48700 1 0 0 connector6-1.sym
{
T 41900 50500 5 10 0 0 0 0 1
device=CONNECTOR_6
T 40200 50700 5 10 1 1 0 0 1
refdes=ICSP
}
T 50100 40500 9 10 1 0 0 0 2
PIC18F4550 Project

T 50100 40300 9 10 1 0 0 0 1
pic18f4550.sch
T 50300 40100 9 10 1 0 0 0 1
1
T 52100 40100 9 10 1 0 0 0 1
3
T 54400 40300 9 10 1 0 0 0 1
1
T 54000 40100 9 10 1 0 0 0 1
Elliott D. Neyme
T 40600 50500 9 10 1 0 0 0 1
MCLR/Vpp
T 40600 50200 9 10 1 0 0 0 1
Vdd
T 40600 49900 9 10 1 0 0 0 1
Ground
T 40600 49600 9 10 1 0 0 0 1
PGD (ICSPDAT)
T 40600 49300 9 10 1 0 0 0 1
PGD (ICSPCLK)
T 40600 49000 9 10 1 0 0 0 1
PGM (LVP)
N 45400 45200 43900 45200 4
N 43900 45200 43900 49800 4
N 44100 45500 48000 45500 4
N 44100 45500 44100 50100 4
N 45100 48500 45100 50400 4
N 45400 48500 45100 48500 4
N 50800 48500 50800 49500 4
N 41800 49500 50800 49500 4
N 41800 49200 51000 49200 4
N 51000 49200 51000 48200 4
N 51000 48200 50800 48200 4
C 47800 46100 1 0 0 5V-plus-1.sym
C 47900 45000 1 0 0 gnd-1.sym
N 48000 45500 48000 46100 4
N 48000 46100 51200 46100 4
N 45400 45200 45400 45300 4
N 45400 45300 48700 45300 4
N 48700 45800 51300 45800 4
N 48700 45800 48700 45300 4
C 43200 41100 1 0 0 capacitor-1.sym
{
T 43400 41800 5 10 0 0 0 0 1
device=CAPACITOR
T 43400 41500 5 10 1 1 0 0 1
refdes=C2
T 43400 42000 5 10 0 0 0 0 1
symversion=0.1
}
C 43200 41800 1 0 0 capacitor-1.sym
{
T 43400 42500 5 10 0 0 0 0 1
device=CAPACITOR
T 43400 42300 5 10 1 1 0 0 1
refdes=C1
T 43400 42700 5 10 0 0 0 0 1
symversion=0.1
}
N 43200 41300 43200 42000 4
N 43200 41700 42500 41700 4
C 42400 41400 1 0 0 gnd-1.sym
N 45400 45800 43700 45800 4
C 40400 43300 1 0 0 pwrjack-1.sym
{
T 40500 43800 5 10 0 0 0 0 1
device=PWRJACK
T 40400 43800 5 10 1 1 0 0 1
refdes=Audio In
}
C 40300 45800 1 0 0 pwrjack-1.sym
{
T 40400 46300 5 10 0 0 0 0 1
device=PWRJACK
T 40300 46300 5 10 1 1 0 0 1
refdes=Audio Out
T 40300 45800 5 10 0 1 0 0 1
netname=Wez
}
C 40900 47800 1 270 0 pot-1.sym
{
T 41800 47000 5 10 0 0 270 0 1
device=VARIABLE_RESISTOR
T 42400 47000 5 10 0 0 270 0 1
footprint=none
T 41400 47100 5 10 1 1 270 0 1
refdes=R6
}
C 42600 44800 1 0 0 gnd-1.sym
N 41500 47300 44500 47300 4
C 44500 48100 1 0 0 resistor-1.sym
{
T 44800 48500 5 10 0 0 0 0 1
device=RESISTOR
T 44700 48400 5 10 1 1 0 0 1
refdes=R2
}
C 44500 47800 1 0 0 resistor-1.sym
{
T 44800 48200 5 10 0 0 0 0 1
device=RESISTOR
T 44700 48100 5 10 1 1 0 0 1
refdes=R3
}
C 44500 47500 1 0 0 resistor-1.sym
{
T 44800 47900 5 10 0 0 0 0 1
device=RESISTOR
T 44700 47800 5 10 1 1 0 0 1
refdes=R4
}
C 44500 47200 1 0 0 resistor-1.sym
{
T 44800 47600 5 10 0 1 0 0 1
device=RESISTOR
T 44700 47500 5 10 1 1 0 0 1
refdes=R5
}
C 42400 47600 1 0 0 2N3904-1.sym
{
T 43300 48300 5 10 0 0 0 0 1
device=2N3904
T 43300 48100 5 10 1 1 0 0 1
refdes=Q?
T 43200 47700 5 10 0 0 0 0 1
footprint=TO92
}
C 53300 42100 1 0 0 LCD-1.sym
{
T 54300 47675 5 10 0 0 0 0 1
device=LCD
}
N 45100 50400 41800 50400 4
N 44100 50100 41800 50100 4
N 43900 49800 41800 49800 4
N 42400 48100 41000 48100 4
N 41000 48100 41000 47800 4
N 43000 47600 43000 46100 4
C 41200 45000 1 0 0 transformer-1.sym
{
T 41500 46300 5 10 1 1 0 0 1
refdes=T1
T 41500 46300 5 10 0 0 0 0 1
device=transformer
}
N 41200 45900 41200 45100 4
N 43700 45800 43700 43600 4
N 43700 43600 42800 43600 4
C 41300 42500 1 0 0 transformer-1.sym
{
T 41600 43800 5 10 1 1 0 0 1
refdes=T2
T 41600 43800 5 10 0 0 0 0 1
device=transformer
}
C 42700 42300 1 0 0 gnd-1.sym
N 41300 43400 41300 42600 4
C 42100 48500 1 0 0 resistor-1.sym
{
T 42400 48900 5 10 0 0 0 0 1
device=RESISTOR
T 42000 48800 5 10 1 1 0 0 1
refdes=R1
}
N 45400 44900 44100 44900 4
N 44100 44900 44100 42000 4
N 45400 44600 44400 44600 4
N 43300 41300 44400 41300 4
N 44400 41300 44400 44600 4
N 51200 46100 51200 46600 4
N 53300 46600 51200 46600 4
N 53300 46900 51300 46900 4
N 51300 46900 51300 45800 4
N 51300 45500 50800 45500 4
N 53300 43300 51200 43300 4
N 51200 43300 51200 45200 4
N 50800 45200 51200 45200 4
N 53300 43600 51100 43600 4
N 51100 43600 51100 44900 4
N 50800 44900 51100 44900 4
N 53300 43900 51000 43900 4
N 51000 43900 51000 44600 4
N 50800 44600 51000 44600 4
N 45000 43100 45000 42400 4
N 45000 42400 52800 42400 4
N 45400 43100 45000 43100 4
N 45400 42800 45300 42800 4
N 45300 42800 45300 42300 4
N 45300 42300 52900 42300 4
N 52900 45700 53300 45700 4
N 52800 46000 53300 46000 4
N 50800 42800 53000 42800 4
N 53000 45400 53300 45400 4
C 51500 46000 1 0 0 pot-1.sym
{
T 52300 46900 5 10 0 0 0 0 1
device=VARIABLE_RESISTOR
T 52100 46400 5 10 1 1 0 0 1
refdes=R7
T 52300 47500 5 10 0 0 0 0 1
footprint=none
}
C 51400 45800 1 0 0 gnd-1.sym
N 52400 46100 53300 46100 4
N 53300 46100 53300 46300 4
N 52800 42400 52800 45100 4
N 52800 45100 53300 45100 4
N 52900 42300 52900 44800 4
N 53300 44800 52800 44800 4
N 53000 42800 53000 44500 4
N 53000 44500 53300 44500 4
N 50800 43100 53100 43100 4
N 53100 43100 53100 44200 4
N 53300 44200 53100 44200 4
N 51300 45500 51300 43000 4
N 51300 43000 53300 43000 4
N 44500 48200 44500 47300 4
N 45400 47000 41900 47000 4
C 41900 48600 1 0 0 5V-plus-1.sym
N 43000 46100 42700 46100 4
