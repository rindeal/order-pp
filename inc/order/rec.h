// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.

#include "order/cm.h"
#include "order/def.h"
#include "order/eval.h"
#include "order/output.h"
#include "order/pm.h"
#include "order/prelude.h"
#include "order/util.h"

#define ORDER_PP_ID() ORDER_PP

#define ORDER_PP_FIND(_) ORDER_PP_FX(EVAL,(ORDER_PP_FIND_GT_0()))
#define ORDER_PP_EVAL(i) ORDER_PP_EVAL_##i

#define ORDER_PP_IS_ACTIVE(i) ORDER_PP_TEST(ORDER_PP_IF_,ORDER_PP_SCAN_##i(ORDER_PP_IS_EDIBLE_TEST()),0,)

#define ORDER_PP_FIND_GT_0() ORDER_PP_IS_ACTIVE(2)(ORDER_PP_FIND_,GT_2,IN_1_2)()
#define ORDER_PP_FIND_IN_1_2() ORDER_PP_IS_ACTIVE(1)(,2,1)
#define ORDER_PP_FIND_GT_2() ORDER_PP_IS_ACTIVE(6)(ORDER_PP_FIND_,GT_6,IN_3_6)()
#define ORDER_PP_FIND_IN_3_4() ORDER_PP_IS_ACTIVE(3)(,4,3)
#define ORDER_PP_FIND_IN_3_6() ORDER_PP_IS_ACTIVE(4)(ORDER_PP_FIND_IN_,3_4,5_6)()
#define ORDER_PP_FIND_IN_5_6() ORDER_PP_IS_ACTIVE(5)(,6,5)
#define ORDER_PP_FIND_GT_6() ORDER_PP_IS_ACTIVE(14)(ORDER_PP_FIND_,GT_14,IN_7_14)()
#define ORDER_PP_FIND_IN_7_8() ORDER_PP_IS_ACTIVE(7)(,8,7)
#define ORDER_PP_FIND_IN_7_10() ORDER_PP_IS_ACTIVE(8)(ORDER_PP_FIND_IN_,7_8,9_10)()
#define ORDER_PP_FIND_IN_9_10() ORDER_PP_IS_ACTIVE(9)(,10,9)
#define ORDER_PP_FIND_IN_7_14() ORDER_PP_IS_ACTIVE(10)(ORDER_PP_FIND_IN_,7_10,11_14)()
#define ORDER_PP_FIND_IN_11_12() ORDER_PP_IS_ACTIVE(11)(,12,11)
#define ORDER_PP_FIND_IN_11_14() ORDER_PP_IS_ACTIVE(12)(ORDER_PP_FIND_IN_,11_12,13_14)()
#define ORDER_PP_FIND_IN_13_14() ORDER_PP_IS_ACTIVE(13)(,14,13)
#define ORDER_PP_FIND_GT_14() ORDER_PP_IS_ACTIVE(30)(ORDER_PP_FIND_,GT_30,IN_15_30)()
#define ORDER_PP_FIND_IN_15_16() ORDER_PP_IS_ACTIVE(15)(,16,15)
#define ORDER_PP_FIND_IN_15_18() ORDER_PP_IS_ACTIVE(16)(ORDER_PP_FIND_IN_,15_16,17_18)()
#define ORDER_PP_FIND_IN_17_18() ORDER_PP_IS_ACTIVE(17)(,18,17)
#define ORDER_PP_FIND_IN_15_22() ORDER_PP_IS_ACTIVE(18)(ORDER_PP_FIND_IN_,15_18,19_22)()
#define ORDER_PP_FIND_IN_19_20() ORDER_PP_IS_ACTIVE(19)(,20,19)
#define ORDER_PP_FIND_IN_19_22() ORDER_PP_IS_ACTIVE(20)(ORDER_PP_FIND_IN_,19_20,21_22)()
#define ORDER_PP_FIND_IN_21_22() ORDER_PP_IS_ACTIVE(21)(,22,21)
#define ORDER_PP_FIND_IN_15_30() ORDER_PP_IS_ACTIVE(22)(ORDER_PP_FIND_IN_,15_22,23_30)()
#define ORDER_PP_FIND_IN_23_24() ORDER_PP_IS_ACTIVE(23)(,24,23)
#define ORDER_PP_FIND_IN_23_26() ORDER_PP_IS_ACTIVE(24)(ORDER_PP_FIND_IN_,23_24,25_26)()
#define ORDER_PP_FIND_IN_25_26() ORDER_PP_IS_ACTIVE(25)(,26,25)
#define ORDER_PP_FIND_IN_23_30() ORDER_PP_IS_ACTIVE(26)(ORDER_PP_FIND_IN_,23_26,27_30)()
#define ORDER_PP_FIND_IN_27_28() ORDER_PP_IS_ACTIVE(27)(,28,27)
#define ORDER_PP_FIND_IN_27_30() ORDER_PP_IS_ACTIVE(28)(ORDER_PP_FIND_IN_,27_28,29_30)()
#define ORDER_PP_FIND_IN_29_30() ORDER_PP_IS_ACTIVE(29)(,30,29)
#define ORDER_PP_FIND_GT_30() ORDER_PP_IS_ACTIVE(62)(ORDER_PP_FIND_,GT_62,IN_31_62)()
#define ORDER_PP_FIND_IN_31_32() ORDER_PP_IS_ACTIVE(31)(,32,31)
#define ORDER_PP_FIND_IN_31_34() ORDER_PP_IS_ACTIVE(32)(ORDER_PP_FIND_IN_,31_32,33_34)()
#define ORDER_PP_FIND_IN_33_34() ORDER_PP_IS_ACTIVE(33)(,34,33)
#define ORDER_PP_FIND_IN_31_38() ORDER_PP_IS_ACTIVE(34)(ORDER_PP_FIND_IN_,31_34,35_38)()
#define ORDER_PP_FIND_IN_35_36() ORDER_PP_IS_ACTIVE(35)(,36,35)
#define ORDER_PP_FIND_IN_35_38() ORDER_PP_IS_ACTIVE(36)(ORDER_PP_FIND_IN_,35_36,37_38)()
#define ORDER_PP_FIND_IN_37_38() ORDER_PP_IS_ACTIVE(37)(,38,37)
#define ORDER_PP_FIND_IN_31_46() ORDER_PP_IS_ACTIVE(38)(ORDER_PP_FIND_IN_,31_38,39_46)()
#define ORDER_PP_FIND_IN_39_40() ORDER_PP_IS_ACTIVE(39)(,40,39)
#define ORDER_PP_FIND_IN_39_42() ORDER_PP_IS_ACTIVE(40)(ORDER_PP_FIND_IN_,39_40,41_42)()
#define ORDER_PP_FIND_IN_41_42() ORDER_PP_IS_ACTIVE(41)(,42,41)
#define ORDER_PP_FIND_IN_39_46() ORDER_PP_IS_ACTIVE(42)(ORDER_PP_FIND_IN_,39_42,43_46)()
#define ORDER_PP_FIND_IN_43_44() ORDER_PP_IS_ACTIVE(43)(,44,43)
#define ORDER_PP_FIND_IN_43_46() ORDER_PP_IS_ACTIVE(44)(ORDER_PP_FIND_IN_,43_44,45_46)()
#define ORDER_PP_FIND_IN_45_46() ORDER_PP_IS_ACTIVE(45)(,46,45)
#define ORDER_PP_FIND_IN_31_62() ORDER_PP_IS_ACTIVE(46)(ORDER_PP_FIND_IN_,31_46,47_62)()
#define ORDER_PP_FIND_IN_47_48() ORDER_PP_IS_ACTIVE(47)(,48,47)
#define ORDER_PP_FIND_IN_47_50() ORDER_PP_IS_ACTIVE(48)(ORDER_PP_FIND_IN_,47_48,49_50)()
#define ORDER_PP_FIND_IN_49_50() ORDER_PP_IS_ACTIVE(49)(,50,49)
#define ORDER_PP_FIND_IN_47_54() ORDER_PP_IS_ACTIVE(50)(ORDER_PP_FIND_IN_,47_50,51_54)()
#define ORDER_PP_FIND_IN_51_52() ORDER_PP_IS_ACTIVE(51)(,52,51)
#define ORDER_PP_FIND_IN_51_54() ORDER_PP_IS_ACTIVE(52)(ORDER_PP_FIND_IN_,51_52,53_54)()
#define ORDER_PP_FIND_IN_53_54() ORDER_PP_IS_ACTIVE(53)(,54,53)
#define ORDER_PP_FIND_IN_47_62() ORDER_PP_IS_ACTIVE(54)(ORDER_PP_FIND_IN_,47_54,55_62)()
#define ORDER_PP_FIND_IN_55_56() ORDER_PP_IS_ACTIVE(55)(,56,55)
#define ORDER_PP_FIND_IN_55_58() ORDER_PP_IS_ACTIVE(56)(ORDER_PP_FIND_IN_,55_56,57_58)()
#define ORDER_PP_FIND_IN_57_58() ORDER_PP_IS_ACTIVE(57)(,58,57)
#define ORDER_PP_FIND_IN_55_62() ORDER_PP_IS_ACTIVE(58)(ORDER_PP_FIND_IN_,55_58,59_62)()
#define ORDER_PP_FIND_IN_59_60() ORDER_PP_IS_ACTIVE(59)(,60,59)
#define ORDER_PP_FIND_IN_59_62() ORDER_PP_IS_ACTIVE(60)(ORDER_PP_FIND_IN_,59_60,61_62)()
#define ORDER_PP_FIND_IN_61_62() ORDER_PP_IS_ACTIVE(61)(,62,61)
#define ORDER_PP_FIND_GT_62() ORDER_PP_ERROR_OUT_OF_INTERPRETERS(!)

#define ORDER_PP_ERROR_OUT_OF_INTERPRETERS()

#ifdef ORDER_PP_DEBUG
# define ORDER_PP_EVAL_0(t) ORDER_PP_SCAN_0(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_1(t) ORDER_PP_SCAN_1(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_2(t) ORDER_PP_SCAN_2(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_3(t) ORDER_PP_SCAN_3(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_4(t) ORDER_PP_SCAN_4(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_5(t) ORDER_PP_SCAN_5(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_6(t) ORDER_PP_SCAN_6(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_7(t) ORDER_PP_SCAN_7(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_8(t) ORDER_PP_SCAN_8(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_9(t) ORDER_PP_SCAN_9(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_10(t) ORDER_PP_SCAN_10(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_11(t) ORDER_PP_SCAN_11(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_12(t) ORDER_PP_SCAN_12(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_13(t) ORDER_PP_SCAN_13(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_14(t) ORDER_PP_SCAN_14(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_15(t) ORDER_PP_SCAN_15(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_16(t) ORDER_PP_SCAN_16(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_17(t) ORDER_PP_SCAN_17(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_18(t) ORDER_PP_SCAN_18(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_19(t) ORDER_PP_SCAN_19(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_20(t) ORDER_PP_SCAN_20(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_21(t) ORDER_PP_SCAN_21(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_22(t) ORDER_PP_SCAN_22(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_23(t) ORDER_PP_SCAN_23(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_24(t) ORDER_PP_SCAN_24(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_25(t) ORDER_PP_SCAN_25(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_26(t) ORDER_PP_SCAN_26(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_27(t) ORDER_PP_SCAN_27(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_28(t) ORDER_PP_SCAN_28(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_29(t) ORDER_PP_SCAN_29(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_30(t) ORDER_PP_SCAN_30(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_31(t) ORDER_PP_SCAN_31(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_32(t) ORDER_PP_SCAN_32(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_33(t) ORDER_PP_SCAN_33(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_34(t) ORDER_PP_SCAN_34(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_35(t) ORDER_PP_SCAN_35(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_36(t) ORDER_PP_SCAN_36(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_37(t) ORDER_PP_SCAN_37(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_38(t) ORDER_PP_SCAN_38(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_39(t) ORDER_PP_SCAN_39(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_40(t) ORDER_PP_SCAN_40(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_41(t) ORDER_PP_SCAN_41(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_42(t) ORDER_PP_SCAN_42(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_43(t) ORDER_PP_SCAN_43(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_44(t) ORDER_PP_SCAN_44(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_45(t) ORDER_PP_SCAN_45(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_46(t) ORDER_PP_SCAN_46(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_47(t) ORDER_PP_SCAN_47(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_48(t) ORDER_PP_SCAN_48(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_49(t) ORDER_PP_SCAN_49(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_50(t) ORDER_PP_SCAN_50(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_51(t) ORDER_PP_SCAN_51(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_52(t) ORDER_PP_SCAN_52(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_53(t) ORDER_PP_SCAN_53(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_54(t) ORDER_PP_SCAN_54(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_55(t) ORDER_PP_SCAN_55(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_56(t) ORDER_PP_SCAN_56(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_57(t) ORDER_PP_SCAN_57(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_58(t) ORDER_PP_SCAN_58(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_59(t) ORDER_PP_SCAN_59(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_60(t) ORDER_PP_SCAN_60(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_61(t) ORDER_PP_SCAN_61(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
# define ORDER_PP_EVAL_62(t) ORDER_PP_SCAN_62(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_SYNTAX_CHECK(,t,ORDER_PP_DEF)(t),8EXIT,,)))
#else
# define ORDER_PP_EVAL_0(t) ORDER_PP_SCAN_0(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_1(t) ORDER_PP_SCAN_1(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_2(t) ORDER_PP_SCAN_2(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_3(t) ORDER_PP_SCAN_3(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_4(t) ORDER_PP_SCAN_4(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_5(t) ORDER_PP_SCAN_5(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_6(t) ORDER_PP_SCAN_6(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_7(t) ORDER_PP_SCAN_7(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_8(t) ORDER_PP_SCAN_8(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_9(t) ORDER_PP_SCAN_9(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_10(t) ORDER_PP_SCAN_10(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_11(t) ORDER_PP_SCAN_11(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_12(t) ORDER_PP_SCAN_12(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_13(t) ORDER_PP_SCAN_13(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_14(t) ORDER_PP_SCAN_14(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_15(t) ORDER_PP_SCAN_15(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_16(t) ORDER_PP_SCAN_16(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_17(t) ORDER_PP_SCAN_17(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_18(t) ORDER_PP_SCAN_18(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_19(t) ORDER_PP_SCAN_19(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_20(t) ORDER_PP_SCAN_20(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_21(t) ORDER_PP_SCAN_21(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_22(t) ORDER_PP_SCAN_22(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_23(t) ORDER_PP_SCAN_23(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_24(t) ORDER_PP_SCAN_24(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_25(t) ORDER_PP_SCAN_25(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_26(t) ORDER_PP_SCAN_26(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_27(t) ORDER_PP_SCAN_27(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_28(t) ORDER_PP_SCAN_28(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_29(t) ORDER_PP_SCAN_29(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_30(t) ORDER_PP_SCAN_30(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_31(t) ORDER_PP_SCAN_31(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_32(t) ORDER_PP_SCAN_32(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_33(t) ORDER_PP_SCAN_33(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_34(t) ORDER_PP_SCAN_34(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_35(t) ORDER_PP_SCAN_35(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_36(t) ORDER_PP_SCAN_36(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_37(t) ORDER_PP_SCAN_37(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_38(t) ORDER_PP_SCAN_38(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_39(t) ORDER_PP_SCAN_39(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_40(t) ORDER_PP_SCAN_40(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_41(t) ORDER_PP_SCAN_41(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_42(t) ORDER_PP_SCAN_42(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_43(t) ORDER_PP_SCAN_43(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_44(t) ORDER_PP_SCAN_44(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_45(t) ORDER_PP_SCAN_45(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_46(t) ORDER_PP_SCAN_46(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_47(t) ORDER_PP_SCAN_47(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_48(t) ORDER_PP_SCAN_48(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_49(t) ORDER_PP_SCAN_49(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_50(t) ORDER_PP_SCAN_50(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_51(t) ORDER_PP_SCAN_51(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_52(t) ORDER_PP_SCAN_52(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_53(t) ORDER_PP_SCAN_53(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_54(t) ORDER_PP_SCAN_54(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_55(t) ORDER_PP_SCAN_55(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_56(t) ORDER_PP_SCAN_56(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_57(t) ORDER_PP_SCAN_57(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_58(t) ORDER_PP_SCAN_58(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_59(t) ORDER_PP_SCAN_59(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_60(t) ORDER_PP_SCAN_60(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_61(t) ORDER_PP_SCAN_61(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
# define ORDER_PP_EVAL_62(t) ORDER_PP_SCAN_62(ORDER_PP_OUTPUT(ORDER_PP_CM(,,ORDER_PP_DEF_##t,8EXIT,,)))
#endif

#define ORDER_PP_SCAN_0(x) x
#define ORDER_PP_SCAN_1(x) x
#define ORDER_PP_SCAN_2(x) x
#define ORDER_PP_SCAN_3(x) x
#define ORDER_PP_SCAN_4(x) x
#define ORDER_PP_SCAN_5(x) x
#define ORDER_PP_SCAN_6(x) x
#define ORDER_PP_SCAN_7(x) x
#define ORDER_PP_SCAN_8(x) x
#define ORDER_PP_SCAN_9(x) x
#define ORDER_PP_SCAN_10(x) x
#define ORDER_PP_SCAN_11(x) x
#define ORDER_PP_SCAN_12(x) x
#define ORDER_PP_SCAN_13(x) x
#define ORDER_PP_SCAN_14(x) x
#define ORDER_PP_SCAN_15(x) x
#define ORDER_PP_SCAN_16(x) x
#define ORDER_PP_SCAN_17(x) x
#define ORDER_PP_SCAN_18(x) x
#define ORDER_PP_SCAN_19(x) x
#define ORDER_PP_SCAN_20(x) x
#define ORDER_PP_SCAN_21(x) x
#define ORDER_PP_SCAN_22(x) x
#define ORDER_PP_SCAN_23(x) x
#define ORDER_PP_SCAN_24(x) x
#define ORDER_PP_SCAN_25(x) x
#define ORDER_PP_SCAN_26(x) x
#define ORDER_PP_SCAN_27(x) x
#define ORDER_PP_SCAN_28(x) x
#define ORDER_PP_SCAN_29(x) x
#define ORDER_PP_SCAN_30(x) x
#define ORDER_PP_SCAN_31(x) x
#define ORDER_PP_SCAN_32(x) x
#define ORDER_PP_SCAN_33(x) x
#define ORDER_PP_SCAN_34(x) x
#define ORDER_PP_SCAN_35(x) x
#define ORDER_PP_SCAN_36(x) x
#define ORDER_PP_SCAN_37(x) x
#define ORDER_PP_SCAN_38(x) x
#define ORDER_PP_SCAN_39(x) x
#define ORDER_PP_SCAN_40(x) x
#define ORDER_PP_SCAN_41(x) x
#define ORDER_PP_SCAN_42(x) x
#define ORDER_PP_SCAN_43(x) x
#define ORDER_PP_SCAN_44(x) x
#define ORDER_PP_SCAN_45(x) x
#define ORDER_PP_SCAN_46(x) x
#define ORDER_PP_SCAN_47(x) x
#define ORDER_PP_SCAN_48(x) x
#define ORDER_PP_SCAN_49(x) x
#define ORDER_PP_SCAN_50(x) x
#define ORDER_PP_SCAN_51(x) x
#define ORDER_PP_SCAN_52(x) x
#define ORDER_PP_SCAN_53(x) x
#define ORDER_PP_SCAN_54(x) x
#define ORDER_PP_SCAN_55(x) x
#define ORDER_PP_SCAN_56(x) x
#define ORDER_PP_SCAN_57(x) x
#define ORDER_PP_SCAN_58(x) x
#define ORDER_PP_SCAN_59(x) x
#define ORDER_PP_SCAN_60(x) x
#define ORDER_PP_SCAN_61(x) x
#define ORDER_PP_SCAN_62(x) x
