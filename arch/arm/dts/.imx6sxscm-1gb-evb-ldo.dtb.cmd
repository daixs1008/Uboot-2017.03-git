cmd_arch/arm/dts/imx6sxscm-1gb-evb-ldo.dtb := mkdir -p arch/arm/dts/ ; cat arch/arm/dts/imx6sxscm-1gb-evb-ldo.dts  | arm-buildroot-linux-gnueabihf-gcc -E -Wp,-MD,arch/arm/dts/.imx6sxscm-1gb-evb-ldo.dtb.d.pre.tmp -nostdinc -I./arch/arm/dts -I./arch/arm/dts/include -Iinclude -I./include -I./arch/arm/include -include ./include/linux/kconfig.h -D__ASSEMBLY__ -undef -D__DTS__ -x assembler-with-cpp -o arch/arm/dts/.imx6sxscm-1gb-evb-ldo.dtb.dts.tmp - ; dtc -O dtb -o arch/arm/dts/imx6sxscm-1gb-evb-ldo.dtb -b 0 -i arch/arm/dts/  -Wno-unit_address_vs_reg  -d arch/arm/dts/.imx6sxscm-1gb-evb-ldo.dtb.d.dtc.tmp arch/arm/dts/.imx6sxscm-1gb-evb-ldo.dtb.dts.tmp ; cat arch/arm/dts/.imx6sxscm-1gb-evb-ldo.dtb.d.pre.tmp arch/arm/dts/.imx6sxscm-1gb-evb-ldo.dtb.d.dtc.tmp > arch/arm/dts/.imx6sxscm-1gb-evb-ldo.dtb.d

source_arch/arm/dts/imx6sxscm-1gb-evb-ldo.dtb := arch/arm/dts/imx6sxscm-evb-ldo.dts

deps_arch/arm/dts/imx6sxscm-1gb-evb-ldo.dtb := \
  arch/arm/dts/imx6sxscm-evb.dts \
  arch/arm/dts/include/dt-bindings/gpio/gpio.h \
  arch/arm/dts/include/dt-bindings/input/input.h \
  arch/arm/dts/include/dt-bindings/input/linux-event-codes.h \
  arch/arm/dts/imx6sx.dtsi \
  arch/arm/dts/include/dt-bindings/clock/imx6sx-clock.h \
  arch/arm/dts/include/dt-bindings/interrupt-controller/arm-gic.h \
  arch/arm/dts/include/dt-bindings/interrupt-controller/irq.h \
  arch/arm/dts/imx6sx-pinfunc.h \
  arch/arm/dts/skeleton.dtsi \

arch/arm/dts/imx6sxscm-1gb-evb-ldo.dtb: $(deps_arch/arm/dts/imx6sxscm-1gb-evb-ldo.dtb)

$(deps_arch/arm/dts/imx6sxscm-1gb-evb-ldo.dtb):
