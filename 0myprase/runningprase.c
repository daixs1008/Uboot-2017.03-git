
printf("%s, %d\n"__FILE__,__LINE__);
printf("%s , %s , %d\n", __FILE__, __FUNCTION__,__LINE__);


Uboot  有两个过程，1.配置过程	2.根据配置的内容制作Uboot的过程


配置过程如下：
/*
book@100ask:~/mydevlop/Uboot-2017.03$ make mx6ull_14x14_evk_defconfig
  HOSTCC  scripts/basic/fixdep
  HOSTCC  scripts/kconfig/conf.o
  SHIPPED scripts/kconfig/zconf.tab.c
  SHIPPED scripts/kconfig/zconf.lex.c
  SHIPPED scripts/kconfig/zconf.hash.c
  HOSTCC  scripts/kconfig/zconf.tab.o
  HOSTLD  scripts/kconfig/conf

#
# configuration written to .config   scripts/kconfig/confdata.c:832:	conf_message(_("configuration written to %s"), newname);  //应该是此文件
#

*/
make mrproper   // clean all config
make mx6ull_14x14_evk_defconfig  //config
配置前后对比： 生成：.config  	

book@100ask:~/mydevlop/Uboot-2017.03$ la
api               configs   .git        .mailmap     snapshot.commit
arch              disk      .gitignore  MAINTAINERS  test
board             doc       include     Makefile     tools
.checkpatch.conf  drivers   Kbuild      net          .travis.yml
cmd               dts       Kconfig     post         uboot2017.3.txt
common            examples  lib         README       Uboot2.17.txt
config.mk         fs        Licenses    scripts      uboot.txt
book@100ask:~/mydevlop/Uboot-2017.03$ la
api               configs   .gitignore   Makefile         .travis.yml
arch              disk      include      net              uboot2017.3.txt
board             doc       Kbuild       post             Uboot2.17.txt
.checkpatch.conf  drivers   Kconfig      README           uboot.txt
cmd               dts       lib          scripts
common            examples  Licenses     snapshot.commit
.config           fs        .mailmap     test
config.mk         .git      MAINTAINERS  tools
book@100ask:~/mydevlop/Uboot-2017.03$ 


3
scripts/kconfig/conf
--defconfig=arch/../configs/mx6ull_14x14_evk_defconfig
Kconfig

str=ARM architecture
str=ARM debug
str=General setup
str=Boot images
str=API
str=Boot timing
str=Boot media
str=Console
str=Start-up hooks
str=SPL / TPL
str=Command line interface
str=Autoboot options
str=FASTBOOT
str=Commands
str=Info commands
str=Boot commands
str=Environment commands
str=Memory commands
str=Device access commands
str=Shell scripting commands
str=Network commands
str=Misc commands
str=Power commands
str=Security commands
str=Firmware commands
str=Filesystem commands
str=Partition Types
str=Device Tree Control
str=Device Drivers
str=Generic Driver Options
str=SATA/SCSI device support
str=Clock
str=Hardware crypto devices
str=Demo for driver model
str=DFU support
str=DMA Support
str=FPGA support
str=GPIO Support
str=I2C support
str=LED Support
str=Mailbox Controller Support
str=Memory Controller drivers
str=Multifunction device drivers
str=MMC Host controller Support
str=MTD Support
str=NAND Device Support
str=Generic NAND options
str=SPI Flash Support
str=UBI support
str=Pin controllers
str=Power
str=Power Domain Support
str=Remote Processor drivers
str=Reset Controller Support
str=Real Time Clock
str=Serial drivers
str=Sound support
str=SPI Support
str=SPMI support
str=System reset device drivers
str=Timer Support
str=TPM support
str=USB Host Controller Drivers
str=MUSB Controller Driver
str=ULPI drivers
str=USB peripherals
str=Graphics support
str=TrueType Fonts
str=WATCHDOG support
str=File systems
str=Library routines
str=Hashing Support
str=Compression Support
str=System tables
#



int main(int ac, char **av)   //Uboot-2017.03\scripts\Kconfig\conf.c

} else if (input_mode != listnewconfig) {
	  printf-("ssss\n");  //根据打印 走此分支
		if (conf_write(NULL)) {

int conf_write(const char *name)
	conf_message-(_("configuration written to %s"), newname); 


static void conf_message(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	if (conf_message_callback)
		conf_message_callback(fmt, ap);
	va_end(ap);
}



//Uboot-2017.03\doc\uImage.FIT\beaglebone_vboot.txt


arch\arm\imx-common\cpu.c

2.-CPU:   Freescale i.MX6ULL rev1.1 696 MHz (running at 396 MHz)
3.-CPU:   Industrial temperature grade (-40C to 105C) at 37C
4.-Reset cause: POR


ldr	lr, =board_init_r	/* this is auto-relocated! */ // -arch\arm\lib\crt0.S

void board_init_r--(gd_t *new_gd, ulong dest_addr)  //  -common\board_r.c

if (initcall_run_list(init_sequence_f))   //  -lib\initcall.c
	
	init_sequence_f[]   //  -common\board_r.c
	{
		..
		print_cpuinfo  // 2.- CPU:   Freescale i.MX6ULL rev1.1 696 MHz (running at 396 MHz)
		..

	}
	
arch\arm\dts\imx6ull-14x14-evk.dts

5.-Model: Freescale i.MX6 ULL 14x14 EVK Board  

6.-Board: MX6ULL 14x14 EVK   // -board\freescale\mx6ullevk\mx6ullevk.c


init_sequence_f[] = { }
 
int __weak show_board_info(void)
int checkboard-(void)
puts("Board: MX6ULL 14x14 EVK\n");  //6.-Board: MX6ULL 14x14 EVK



#ifdef CONFIG_CMD_MEMINFO
U_BOOT_CMD(
	meminfo,	3,	1,	do_mem_info,
	"display memory information",
	""
);
#endif

static int do_mem_info-(cmd_tbl_t *cmdtp, int flag, int argc,		       char * const argv[])
__weak void board_show_dram-(phys_size_t size)
	puts("DRAM:  ");      //7.-DRAM:  512 MiB




-arch\arm\imx-common\video.c


static init_fnc_t init_sequence_r[] = {}
	int stdio_add_devices(void)
		int drv_video_init(void)
			int board_video_skip-(void)
				printf("Display: %s (%ux%u)\n",  //9.-Display: TFT7016 (1024x600)
	


U_BOOT_DRIVER(coreboot_video) = {
	.name	= "coreboot_video",
	.id	= UCLASS_VIDEO,
	.of_match = coreboot_video_ids,
	.probe	= coreboot_video_probe,
};
	

static int coreboot_video_probe(struct udevice *dev)
	printf("Video: ");   //  10.-Video: 1024x600x24
	printf-("%dx%dx%d\n", uc_priv->xsize, uc_priv->ysize, vesa->bits_per_pixel); // //  10.-Video: 1024x600x24 


main_loop
	autoboot_command-(s);
		void autoboot_command-(const char *s)
			i f (stored_bootdelay != -1 && s && !abortboot(stored_bootdelay)) {
				static int abortboot-(int bootdelay)
					static int __abortboot-(int bootdelay)
						printf-("Hit any key to stop autoboot: %2d ", bootdelay);    //16.-Hit any key to stop autoboot:  0


U_BOOT_CMD(
	mmc, 29, 1, do_mmcops,  ..
	

static int do_mmcops(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
	cp = find_cmd_tbl(argv[1], cmd_mmc, ARRAY_SIZE(cmd_mmc));
		static cmd_tbl_t cmd_mmc[] = {
			U_BOOT_CMD_MKENT-(dev, 3, 0, do_mmc_dev, "", ""),
				static int do_mmc_dev(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
					printf("switch to partitions #%d, %s\n",     //18.-switch to partitions #0, OK 




mmc_read_file in bubt.c (cmd\mvebu) : 	if (fs_set_blk_dev("mmc", "0", FS_TYPE_ANY)) {
usb_read_file in bubt.c (cmd\mvebu) : 	if (fs_set_blk_dev("usb", "0", FS_TYPE_ANY)) {
fs.c (fs) line 195 : int fs_set_blk_dev(const char *ifname, const char *dev_part_str, int fstype)
do_size in fs.c (fs) : 	if (fs_set_blk_dev(argv[1], argv[2], fstype))
do_load in fs.c (fs) : 	if (fs_set_blk_dev(argv[1], (argc >= 3) ? argv[2] : NULL, fstype))
do_ls in fs.c (fs) : 	if (fs_set_blk_dev(argv[1], (argc >= 3) ? argv[2] : NULL, fstype))
file_exists in fs.c (fs) : 	if (fs_set_blk_dev(dev_type, dev_part, fstype))
do_save in fs.c (fs) : 	if (fs_set_blk_dev(argv[1], argv[2], fstype))
do_fs_uuid in fs.c (fs) : 	if (fs_set_blk_dev(argv[1], argv[2], fstype))
do_fs_type in fs.c (fs) : 	if (fs_set_blk_dev(argv[1], argv[2], FS_TYPE_ANY))



或者--static struct fstype_info *fs_get_info(int fstype)
		for (i = 0, info = fstypes; i < ARRAY_SIZE(fstypes) - 1; i++, info++) {
		if (fstype == info->fstype)
			return info;
	}

		
或者--int fs_set_blk_dev(const char *ifname, const char *dev_part_str, int fstype)
	for (i = 0, info = fstypes; i < ARRAY_SIZE(fstypes);



static struct fstype_info fstypes[] = {}
	
.probe = fs_probe_unsupported,
static inline int fs_probe_unsupported-(struct blk_desc *fs_dev_desc,  disk_partition_t *fs_partition)
printf("** Unrecognized filesystem type **\n");  //22.-** Unrecognized filesystem type **





--cmd\onenand.c


U_BOOT_CMD(
	onenand,	CONFIG_SYS_MAXARGS,	1,	do_onenand,


#ifdef CONFIG_NEEDS_MANUAL_RELOC
void onenand_reloc(void) {
	fixup_cmdtable(cmd_onenand_sub, ARRAY_SIZE(cmd_onenand_sub));
}
#endif



static int do_onenand(cmd_tbl_t * cmdtp, int flag, int argc, char * const argv[])
c = find_cmd_tbl(argv[0], &cmd_onenand_sub[0], ARRAY_SIZE(cmd_onenand_sub));


static cmd_tbl_t cmd_onenand_sub[] = {
	U_BOOT_CMD_MKENT(info, 1, 0, do_onenand_info, "", ""),
	U_BOOT_CMD_MKENT(bad, 1, 0, do_onenand_bad, "", ""),
	U_BOOT_CMD_MKENT(read, 4, 0, do_onenand_read, "", ""),

static int do_onenand_read(cmd_tbl_t * cmdtp, int flag, int argc, char * const argv[])
printf(" %d bytes read: %s\n", retlen, ret ? "ERROR" : "OK");  //23.-7924928 bytes read in 408 ms (18.5 MiB/s)



include\configs\mx6ullevk.h (include\configs) line 154 : 	"mmcboot=echo Booting from mmc ...; " \
include\configs\mx6ul_14x14_evk.h (include\configs) line 155 : 	"mmcboot=echo Booting from mmc ...; " \


24.-Booting from mmc ...   //-include\configs\mx6ullevk.h   //-include\configs\mx6ul_14x14_evk.h


//26.-Kernel image @ 0x80800000 [ 0x000000 - 0x78ecc0 ]


U_BOOT_CMD(
	pxe, 3, 1, do_pxe,


static int do_pxe(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])


cp = find_cmd_tbl(argv[0], cmd_pxe_sub, ARRAY_SIZE(cmd_pxe_sub));


static cmd_tbl_t cmd_pxe_sub[] = {
	U_BOOT_CMD_MKENT(get, 1, 1, do_pxe_get, "", ""),
	U_BOOT_CMD_MKENT(boot, 2, 1, do_pxe_boot, "", "")
};

static int do_pxe_boot(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])


U_BOOT_CMD(
	sysboot, 7, 1, do_sysboot,

static int do_sysboot(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])


static void handle_pxe_menu(cmd_tbl_t *cmdtp, struct pxe_menu *cfg)
	static int label_boot(cmd_tbl_t *cmdtp, struct pxe_label *label)  ///\cmd\pxe.c
		int do_bootz(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
			static int bootz_start(cmd_tbl_t *cmdtp, int flag, int argc,char * const argv[], bootm_headers_t *images)
				ret = bootz_setup(images->ep, &zi_start, &zi_end);


	if (!bootz_setup((ulong)header, &start, &end))

int do_bootm(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
	ret = bootz_setup(load_addr, &zi_start, &zi_end);


int bootz_setup(ulong image, ulong *start, ulong *end)  //--arch\arm\lib\zimage.c

printf("Kernel image @ %#08lx [ %#08lx - %#08lx ]\n",image, *start, *end); 	//26.-Kernel image @ 0x80800000 [ 0x000000 - 0x78ecc0 ]



U_BOOT_CMD(
	bootz,	CONFIG_SYS_MAXARGS,	1,	do_bootz,

int do_bootz(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
	int do_bootm_states(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[],	    int states, bootm_headers_t *images, int boot_progress)
		static int bootm_find_other(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
		{
			if (((images.os.type == IH_TYPE_KERNEL) ||
			     (images.os.type == IH_TYPE_KERNEL_NOLOAD) ||
			     (images.os.type == IH_TYPE_MULTI)) &&
			    (images.os.os == IH_OS_LINUX ||
				 images.os.os == IH_OS_VXWORKS))
				return bootm_find_images(flag, argc, argv);




U_BOOT_CMD(
	bootz,	CONFIG_SYS_MAXARGS,	1,	do_bootz,

int do_bootz(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
	static int bootz_start(cmd_tbl_t *cmdtp, int flag, int argc,	char * const argv[], bootm_headers_t *images)
		int bootm_find_images(int flag, int argc, char * const argv[])
			int boot_get_fdt(int flag, int argc, char * const argv[], uint8_t arch,	bootm_headers_t *images, char **of_flat_tree, ulong *of_size)
				printf("## Flattened Device Tree blob at %08lx\n",  //27.-## Flattened Device Tree blob at 83000000



//29.-   Using Device Tree in place at 83000000, end 8300c5e1
1.
int do_bootm_states(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[], int states, bootm_headers_t *images, int boot_progress)
	ret = boot_relocate_fdt(&images->lmb, &images->ft_addr,
					&images->ft_len);
	printf("   Using Device Tree in place at %p, end %p\n",   //29.-   Using Device Tree in place at 83000000, end 8300c5e1


2.
int do_bootm_states(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[], int states, bootm_headers_t *images, int boot_progress)
	boot_fn = bootm_os_get_boot_func(images->os.os);


boot_os_fn *bootm_os_get_boot_func(int os)
	/* relocate boot function table */
		for (i = 0; i < ARRAY_SIZE(boot_os); i++)
			if (boot_os[i] != NULL)
				boot_os[i] += gd->reloc_off;

static boot_os_fn *boot_os[] = {}
	

static int do_bootm_vxworks(int flag, int argc, char * const argv[],  bootm_headers_t *images)
	void do_bootvx_fdt(bootm_headers_t *images)
		ret = boot_relocate_fdt(lmb, of_flat_tree, &of_size);
		printf("   Using Device Tree in place at %p, end %p\n",   //29.-   Using Device Tree in place at 83000000, end 8300c5e1

3.

static boot_os_fn *boot_os[] = {

int do_bootm_linux(int flag, int argc, char * const argv[], bootm_headers_t *images)
static void boot_prep_linux(bootm_headers_t *images)
int image_setup_linux(bootm_headers_t *images)
	int boot_relocate_fdt(struct lmb *lmb, char **of_flat_tree, ulong *of_size)
		printf("   Using Device Tree in place at %p, end %p\n",   //29.-   Using Device Tree in place at 83000000, end 8300c5e1


//30.-Modify /soc/aips-bus@02200000/epdc@0228c000:status disabled


static int do_fdt(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
	int err = ft_system_setup(working_fdt, gd->bd);


U_BOOT_CMD(
	bootefi, 3, 0, do_bootefi,

static int do_bootefi(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
	static unsigned long do_bootefi_exec(void *efi, void *fdt)
		if (image_setup_libfdt(&img, fdt, 0, NULL)) {



int do_bootm_linux(int flag, int argc, char * const argv[],   bootm_headers_t *images)
	static void boot_prep_linux(bootm_headers_t *images)
		int image_setup_linux(bootm_headers_t *images)
			int image_setup_libfdt(bootm_headers_t *images, void *blob, int of_size, struct lmb *lmb)
				fdt_ret = ft_system_setup(blob, gd->bd);


int ft_system_setup(void *blob, bd_t *bd)
printf("Modify %s:%s disabled\n",			   //30.-Modify /soc/aips-bus@02200000/epdc@0228c000:status disabled



