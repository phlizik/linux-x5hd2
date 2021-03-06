#include "higmac.h"
#include "phy_fix.h"

static const u32 phy_fix_param[] = {
	0x33f9,0xbd,
	0x33fa,0x34,
	0x33fb,0x00,
	0x33fc,0x39,
	0x3400,0x39,
	0x3401,0xCC,
	0x3402,0x00,
	0x3403,0x02,
	0x3404,0xFD,
	0x3405,0xFF,
	0x3406,0xF0,
	0x3407,0xF6,
	0x3408,0x34,
	0x3409,0xAB,
	0x340A,0x26,
	0x340B,0x21,
	0x340C,0xC6,
	0x340D,0x01,
	0x340E,0xF7,
	0x340F,0x34,
	0x3410,0xAB,
	0x3411,0xCC,
	0x3412,0x34,
	0x3413,0x2E,
	0x3414,0xFD,
	0x3415,0x00,
	0x3416,0xD1,
	0x3417,0xF6,
	0x3418,0x20,
	0x3419,0xAA,
	0x341A,0xCB,
	0x341B,0x04,
	0x341C,0xC4,
	0x341D,0x1F,
	0x341E,0xF7,
	0x341F,0x34,
	0x3420,0xAC,
	0x3421,0xC1,
	0x3422,0x0F,
	0x3423,0x23,
	0x3424,0x05,
	0x3425,0xC6,
	0x3426,0x0F,
	0x3427,0xF7,
	0x3428,0x34,
	0x3429,0xAC,
	0x342A,0xF7,
	0x342B,0x20,
	0x342C,0xAA,
	0x342D,0x39,
	0x342E,0xF6,
	0x342F,0x01,
	0x3430,0xC0,
	0x3431,0xC1,
	0x3432,0x13,
	0x3433,0x24,
	0x3434,0x75,
	0x3435,0xBD,
	0x3436,0xEE,
	0x3437,0x8F,
	0x3438,0x34,
	0x3439,0x5F,
	0x343A,0x34,
	0x343B,0x62,
	0x343C,0x34,
	0x343D,0x6B,
	0x343E,0x34,
	0x343F,0x6F,
	0x3440,0x34,
	0x3441,0x73,
	0x3442,0x34,
	0x3443,0x76,
	0x3444,0x34,
	0x3445,0x7A,
	0x3446,0x34,
	0x3447,0x7E,
	0x3448,0x34,
	0x3449,0x82,
	0x344A,0x34,
	0x344B,0x86,
	0x344C,0x34,
	0x344D,0x8A,
	0x344E,0x34,
	0x344F,0x8D,
	0x3450,0x34,
	0x3451,0x91,
	0x3452,0x34,
	0x3453,0x95,
	0x3454,0x34,
	0x3455,0x98,
	0x3456,0x34,
	0x3457,0x9C,
	0x3458,0x34,
	0x3459,0xA0,
	0x345A,0x34,
	0x345B,0xA4,
	0x345C,0x34,
	0x345D,0xA7,
	0x345E,0x39,
	0x345F,0xBD,
	0x3460,0xBC,
	0x3461,0x25,
	0x3462,0xBD,
	0x3463,0xBC,
	0x3464,0x33,
	0x3465,0xC6,
	0x3466,0x08,
	0x3467,0xF7,
	0x3468,0x20,
	0x3469,0xA8,
	0x346A,0x39,
	0x346B,0xBD,
	0x346C,0xBC,
	0x346D,0x71,
	0x346E,0x39,
	0x346F,0xBD,
	0x3470,0xBC,
	0x3471,0x94,
	0x3472,0x39,
	0x3473,0xBD,
	0x3474,0xBD,
	0x3475,0x07,
	0x3476,0xBD,
	0x3477,0xBD,
	0x3478,0x38,
	0x3479,0x39,
	0x347A,0xBD,
	0x347B,0xBD,
	0x347C,0x90,
	0x347D,0x39,
	0x347E,0xBD,
	0x347F,0xBD,
	0x3480,0xC0,
	0x3481,0x39,
	0x3482,0xBD,
	0x3483,0xBE,
	0x3484,0x07,
	0x3485,0x39,
	0x3486,0xBD,
	0x3487,0xBE,
	0x3488,0x6A,
	0x3489,0x39,
	0x348A,0xBD,
	0x348B,0xBE,
	0x348C,0xB0,
	0x348D,0xBD,
	0x348E,0xBF,
	0x348F,0x05,
	0x3490,0x39,
	0x3491,0xBD,
	0x3492,0xC0,
	0x3493,0x60,
	0x3494,0x39,
	0x3495,0xBD,
	0x3496,0xC0,
	0x3497,0x7E,
	0x3498,0xBD,
	0x3499,0xC0,
	0x349A,0xB2,
	0x349B,0x39,
	0x349C,0xBD,
	0x349D,0xC0,
	0x349E,0xDD,
	0x349F,0x39,
	0x34A0,0xBD,
	0x34A1,0xC1,
	0x34A2,0x7E,
	0x34A3,0x39,
	0x34A4,0xBD,
	0x34A5,0xC1,
	0x34A6,0x9F,
	0x34A7,0xBD,
	0x34A8,0xC1,
	0x34A9,0xBF,
	0x34AA,0x39,
	0x34AB,0x00,
	0x3400,0x01,
	0x33f8,0x01
};

int set_phy_expanded_access_mode(struct phy_device *phy_dev, int access_mode)
{
	int v, ret;

	v = phy_read(phy_dev, MII_MISC_CTL);
	v &= (~0x3);
	v |= (access_mode & 0x3);
	ret = phy_write(phy_dev, MII_MISC_CTL, v);

	return ret;
}

int phy_expanded_read(struct phy_device *phy_dev, u32 reg_addr)
{
	int v, ret;

	v = phy_read(phy_dev, MII_BMCR);
	v |= BMCR_PDOWN;
	phy_write(phy_dev, MII_BMCR, v);

	phy_write(phy_dev, MII_EXPMA, reg_addr);
	ret = phy_read(phy_dev, MII_EXPMD);

	v = phy_read(phy_dev, MII_BMCR);
	v &= (~BMCR_PDOWN);
	phy_write(phy_dev, MII_BMCR, v);

	return ret;
}

int phy_expanded_write(struct phy_device *phy_dev, u32 reg_addr, u16 val)
{
	int v, ret;

	v = phy_read(phy_dev, MII_BMCR);
	v |= BMCR_PDOWN;
	phy_write(phy_dev, MII_BMCR, v);

	phy_write(phy_dev, MII_EXPMA, reg_addr);
	ret = phy_write(phy_dev, MII_EXPMD, val);

	v = phy_read(phy_dev, MII_BMCR);
	v &= (~BMCR_PDOWN);
	phy_write(phy_dev, MII_BMCR, v);

	return ret;
}

int phy_expanded_write_bulk(struct phy_device *phy_dev, const u32 reg_and_val[],
			    int count)
{
	int i, v, ret = 0;
	u32 reg_addr;
	u16 val;

	v = phy_read(phy_dev, MII_BMCR);
	v |= BMCR_PDOWN;
	phy_write(phy_dev, MII_BMCR, v);

	for (i = 0; i < (2 * count); i += 2) {
		reg_addr = reg_and_val[i];
		val = (u16) reg_and_val[i + 1];
		phy_write(phy_dev, MII_EXPMA, reg_addr);
		ret = phy_write(phy_dev, MII_EXPMD, val);
	}

	v = phy_read(phy_dev, MII_BMCR);
	v &= (~BMCR_PDOWN);
	phy_write(phy_dev, MII_BMCR, v);

	return ret;
}

/* fix FEPHY for better eye diagram */
int hisilicon_fephy_fix(struct phy_device *phy_dev)
{
	int count;

	count = sizeof(phy_fix_param) / sizeof(phy_fix_param[0]);
	if (count % 2)
		pr_warn("internal FEPHY fix register count is not right.\n");
	count /= 2;

	phy_expanded_write_bulk(phy_dev, phy_fix_param, count);

	return 0;
}

/*
 * for a better Electromagnetic Compatibility
 */
int realtek_gephy_fix(struct phy_device *phy_dev)
{
#if 0
	int v;

	pr_info("RealTek phy fix: phy id=0x%x\n", phy_dev->phy_id);

	v = phy_read(phy_dev, 16);      /* PHYCR reg */
	v |= 1 << 4;                    /* clk125 remains at logic low */
	phy_write(phy_dev, 16, v);

	phy_write(phy_dev, 31, 0x0007);	/* set to extension page */
	phy_write(phy_dev, 30, 0x00A0);	/* set to extension page 160 */

	v = phy_read(phy_dev, 26);
	v &= ~(1 << 2);			/* enable RXC SSC */
	phy_write(phy_dev, 26, v);

	phy_write(phy_dev, 31, 0x0);	/* back to page 0 */

#endif

	return 0;
}

/* copy from phy_quirk() in hieth-sf/net.c */
int KSZ8051MNL_phy_fix(struct phy_device *phy_dev)
{
	u32 v;

	v = phy_read(phy_dev, 0x1F);
	v |= (1 << 7);       /* set phy RMII 50MHz clk; */
	phy_write(phy_dev, 0x1F, v);

	v = phy_read(phy_dev, 0x16);
	v |= (1 << 1);       /* set phy RMII override; */
	phy_write(phy_dev, 0x16, v);

	return 0;
}

/* copy from phy_quirk() in hieth-sf/net.c */
int KSZ8081RNB_phy_fix(struct phy_device *phy_dev)
{
	u32 v;

	v = phy_read(phy_dev, 0x1F);
	v |= (1 << 7);       /* set phy RMII 50MHz clk; */
	phy_write(phy_dev, 0x1F, v);

	return 0;
}

void phy_register_fixups(void)
{
	phy_register_fixup_for_uid(REALTEK_PHY_ID_8211EG,
			REALTEK_PHY_MASK, realtek_gephy_fix);
	phy_register_fixup_for_uid(HISILICON_PHY_ID_FESTAV200,
			HISILICON_PHY_MASK, hisilicon_fephy_fix);
	phy_register_fixup_for_uid(PHY_ID_KSZ8051MNL,
			DEFAULT_PHY_MASK, KSZ8051MNL_phy_fix);
	phy_register_fixup_for_uid(PHY_ID_KSZ8081RNB,
			DEFAULT_PHY_MASK, KSZ8081RNB_phy_fix);
}
