
1.-分析文件配置过程
book@100ask:~/mydevlop/Uboot-2017.03$ make mx6ull_14x14_evk_defconfig
  HOSTCC  scripts/basic/fixdep
  HOSTCC  scripts/kconfig/conf.o
  HOSTCC  scripts/kconfig/zconf.tab.o
  HOSTLD  scripts/kconfig/conf
#
# configuration written to .config
#
book@100ask:~/mydevlop/Uboot-2017.03$ grep "configuration written to"  -nr
board/bosch/shc/README:38:# configuration written to .config
Binary file scripts/kconfig/zconf.tab.o matches
scripts/kconfig/merge_config.sh:137:	echo "# merged configuration written to $KCONFIG_CONFIG (needs make)"
scripts/kconfig/confdata.c:832:	conf_message(_("configuration written to %s"), newname);  //应该是此文件
Binary file scripts/kconfig/conf matches



