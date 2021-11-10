
1.-U-Boot 2017.03 (May 11 2021 - 09:15:14 +0000)

2.-CPU:   Freescale i.MX6ULL rev1.1 696 MHz (running at 396 MHz)   // -arch\arm\imx-common\cpu.c
3.-CPU:   Industrial temperature grade (-40C to 105C) at 37C   //arch\arm\imx-common\cpu.c
4.-Reset cause: POR                                           //arch\arm\imx-common\cpu.c
5.-Model: Freescale i.MX6 ULL 14x14 EVK Board        //arch\arm\dts\imx6ull-14x14-evk.dts     
6.-Board: MX6ULL 14x14 EVK        //board\freescale\mx6ullevk\mx6ullevk.c
7.-DRAM:  512 MiB
8.-MMC:   FSL_SDHC: 0, FSL_SDHC: 1
9.-Display: TFT7016 (1024x600)  //-arch\arm\imx-common\video.c
10.-Video: 1024x600x24
11.-In:    serial
12.-Out:   serial
13.-Err:   serial
14.-Net:   No ethernet found.
15.-Normal Boot
16.-Hit any key to stop autoboot:  0 //-common\autoboot.c
17.-## Error: "findtee" not defined
18.-switch to partitions #0, OK   //-cmd\mmc.c
19.-mmc1(part 0) is current device
20.-switch to partitions #0, OK
21.-mmc1(part 0) is current device
22.-** Unrecognized filesystem type **
23.-7924928 bytes read in 408 ms (18.5 MiB/s) //-cmd\onenand.c
24.-Booting from mmc ...   //-include\configs\mx6ullevk.h   //-include\configs\mx6ul_14x14_evk.h
25.-38370 bytes read in 51 ms (734.4 KiB/s)
26.-Kernel image @ 0x80800000 [ 0x000000 - 0x78ecc0 ]
27.-## Flattened Device Tree blob at 83000000  //common\image-fdt.c
28.-   Booting using the fdt blob at 0x83000000   ////common\image-fdt.c
29.-   Using Device Tree in place at 83000000, end 8300c5e1
30.-Modify /soc/aips-bus@02200000/epdc@0228c000:status disabled
31.-ft_system_setup for mx6

32.-Starting kernel ...
//进入内核
[    0.000000] 1--Booting Linux on physical CPU 0x0
[    0.000000] 2--Linux version 4.9.88 (book@virtual-machine) (gcc version 7.5.0 (Buildroot 2020.02-g6a1d083-dirty) ) #1 SMP PREEMPT Tue May 11 05:22:35 UTC 2021
[    0.000000] 3--CPU: ARMv7 Processor [410fc075] revision 5 (ARMv7), cr=10c53c7d
[    0.000000] 4--CPU: div instructions available: patching division code