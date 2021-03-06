/******************************************************************************
 *    COPYRIGHT (C) 2013 Czyong. Hisilicon
 *    All rights reserved.
 * ***
 *    Create by Czyong 2013-02-07
 *
******************************************************************************/

#include <linux/err.h>
#include <linux/completion.h>
#include <linux/kernel.h>
#include <asm/mach/resource.h>
#include <asm/system.h>
#include <mach/platform.h>
#include <asm/io.h>
#include <mach/clock.h>
#include "mach/io.h"
#include "../cpu.h"

extern struct device_resource hi3716cv200_hinfc610_device_resource;
/*****************************************************************************/

static struct device_resource *hi3716cv200_device_resource[] = {
	&hi3716cv200_hinfc610_device_resource,
	NULL,
};
/*****************************************************************************/
extern struct clk hi3716cv200_hinfc610_clk;

static struct clk hi3716cv200_uart_clk = {
#ifdef CONFIG_S40_FPGA 
	.rate = 54000000,
#else
	.rate = 83300000,
#endif
};
static struct clk hi3716cv200_uart1_clk = {
#ifdef CONFIG_S40_FPGA 
	.rate = 54000000,
#else
	.rate = 3000000,
#endif
};

static struct clk_lookup hi3716cv200_lookups[] = {
	{
		.dev_id = "hinfc610",
		.clk    = &hi3716cv200_hinfc610_clk,
	}, { /* UART0 */
		.dev_id		= "uart:0",
		.clk		= &hi3716cv200_uart_clk,
	}, { /* UART1 */
		.dev_id		= "uart:1",
		.clk		= &hi3716cv200_uart1_clk,
	}, { /* UART2 */
		.dev_id		= "uart:2",
		.clk		= &hi3716cv200_uart_clk,
	}, { /* UART3 */
		.dev_id		= "uart:3",
		.clk		= &hi3716cv200_uart_clk,
	}, { /* UART4 */
		.dev_id		= "uart:4",
		.clk		= &hi3716cv200_uart_clk,
	},
};
/*****************************************************************************/

static void hi3716cv200_cpu_init(struct cpu_info *info)
{
	info->clk_cpu    = 800000000;
	info->clk_timer  = 24000000;
	info->cpuversion = "";
	clkdev_add_table(hi3716cv200_lookups,
		ARRAY_SIZE(hi3716cv200_lookups));

}
/*****************************************************************************/
/* Hi3716Cv200 */
struct cpu_info hi3716cv200_cpu_info =
{
	.name = "Hi3716Cv200",
	.chipid = _HI3716CV200,
	.chipid_mask = _HI3716CV200_MASK,
	.resource = hi3716cv200_device_resource,
	.init = hi3716cv200_cpu_init,
};

/* Hi3719mv100_a */
struct cpu_info hi3719mv100_a_cpu_info =
{
	.name = "Hi3719mv100_a",
	.chipid = _HI3719MV100_A,
	.chipid_mask = _HI3719MV100_A_MASK,
	.resource = hi3716cv200_device_resource,
	.init = hi3716cv200_cpu_init,
};

/* Hi3718Cv100 */
struct cpu_info hi3718cv100_cpu_info =
{
	.name = "Hi3718Cv100",
	.chipid = _HI3718CV100,
	.chipid_mask = _HI3716CV200_MASK,
	.resource = hi3716cv200_device_resource,
	.init = hi3716cv200_cpu_init,
};

/* Hi3719Cv100 */
struct cpu_info hi3719cv100_cpu_info =
{
	.name = "Hi3719Cv100",
	.chipid = _HI3719CV100,
	.chipid_mask = _HI3716CV200_MASK,
	.resource = hi3716cv200_device_resource,
	.init = hi3716cv200_cpu_init,
};

/* Hi3716Hv200 */
struct cpu_info hi3716hv200_cpu_info =
{
	.name = "Hi3716Hv200",
	.chipid = _HI3716HV200,
	.chipid_mask = _HI3716CV200_MASK,
	.resource = hi3716cv200_device_resource,
	.init = hi3716cv200_cpu_init,
};

