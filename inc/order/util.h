#ifndef ORDER_UTIL_H_VAJK20040620
#define ORDER_UTIL_H_VAJK20040620

// (C) Copyright Vesa Karvonen 2004.
//
//    Distributed under the Boost Software License, Version 1.0.

#define ORDER_PP_FRESH_ID(name) ORDER_PP_EXPAND(ORDER_PP_FRESH_ID_B,(__LINE__,name))
#define ORDER_PP_FRESH_ID_B(line,name) ORDER_PP_ID_##line##_##name

#define ORDER_PP_DEF(t) ORDER_PP_DEF_##t

#define ORDER_PP_BLOCK
#define ORDER_PP_EAT(...)
#define ORDER_PP_EXPAND(l,r) l r
#define ORDER_PP_FX(P,f,x) P##f x
#define ORDER_PP_FGX(P,f,g,x) ORDER_PP_APPLY_FX(,P##f,P##g x)
#define ORDER_PP_CAT(l,r) ORDER_PP_PRIMITIVE_CAT(l,r)
#define ORDER_PP_REVERSE_CAT(l,r) ORDER_PP_PRIMITIVE_CAT(r,l)
#define ORDER_PP_PRIMITIVE_CAT(l,r) l##r
#define ORDER_PP_BOTH(P,...) P##__VA_ARGS__##P
#define ORDER_PP_LEFT(P,...) P##__VA_ARGS__
#define ORDER_PP_RIGHT(P,...) __VA_ARGS__##P
#define ORDER_PP_OPEN(P,...) P##__VA_ARGS__
#define ORDER_PP_OPEN_NP(...) __VA_ARGS__
#define ORDER_PP_REM(...) __VA_ARGS__
#define ORDER_PP_SCAN(...) __VA_ARGS__

#define ORDER_PP_CM_INVOKE(K,...) ORDER_PP_##K(,__VA_ARGS__

#define ORDER_PP_8AP(P,f,x,...) (,P##x,ORDER_PP_OPEN f##P,P##__VA_ARGS__)

#define ORDER_PP_8REMAP_10(P,_0,_1,K,...) ORDER_PP_##K(,_1##P,_0##P,P##__VA_ARGS__)

#define ORDER_PP_8REMAP_021(P,_0,_1,_2,K,...) ORDER_PP_##K(,_0##P,_2##P,_1##P,P##__VA_ARGS__)
#define ORDER_PP_8REMAP_102(P,_0,_1,_2,K,...) ORDER_PP_##K(,_1##P,_0##P,_2##P,P##__VA_ARGS__)
#define ORDER_PP_8REMAP_120(P,_0,_1,_2,K,...) ORDER_PP_##K(,_1##P,_2##P,_0##P,P##__VA_ARGS__)
#define ORDER_PP_8REMAP_201(P,_0,_1,_2,K,...) ORDER_PP_##K(,_2##P,_0##P,_1##P,P##__VA_ARGS__)
#define ORDER_PP_8REMAP_210(P,_0,_1,_2,K,...) ORDER_PP_##K(,_2##P,_1##P,_0##P,P##__VA_ARGS__)

#define ORDER_PP_8REMAP_2013(P,_0,_1,_2,_3,K,...) ORDER_PP_##K(,_2##P,_0##P,_1##P,_3##P,P##__VA_ARGS__)
#define ORDER_PP_8REMAP_3012(P,_0,_1,_2,_3,K,...) ORDER_PP_##K(,_3##P,_0##P,_1##P,_2##P,P##__VA_ARGS__)

#define ORDER_PP_8REMAP_01120(P,_0,_1,_2,K,...) ORDER_PP_##K(,_0##P,_1##P,_1##P,_2##P,_0##P,P##__VA_ARGS__)
#define ORDER_PP_8REMAP_10021(P,_0,_1,_2,K,...) ORDER_PP_##K(,_1##P,_0##P,_0##P,_2##P,_1##P,P##__VA_ARGS__)

#define ORDER_PP_FST(_0,...) _0
#define ORDER_PP_8FST(P,x,...) (,ORDER_PP_FST x##P,P##__VA_ARGS__)

#define ORDER_PP_RST(_0,...) __VA_ARGS__
#define ORDER_PP_8RST(P,x,...) (,ORDER_PP_RST x##P,P##__VA_ARGS__)

#define ORDER_PP_NUM_ARGS_8(_,_8,_7,_6,_5,_4,_3,_2,_1,x,...) x

#define ORDER_PP_IF_8true(P,c,...) P##c
#define ORDER_PP_IF_8false(P,c,...) P##__VA_ARGS__

#define ORDER_PP_IF_NOT_8true(P,c,...) P##__VA_ARGS__
#define ORDER_PP_IF_NOT_8false(P,c,...) P##c

#define ORDER_PP_WHEN_8true(P,...) P##__VA_ARGS__
#define ORDER_PP_WHEN_8false(...)

#define ORDER_PP_UNLESS_8true(...)
#define ORDER_PP_UNLESS_8false(P,...) P##__VA_ARGS__

#define ORDER_PP_SELECT_4(c0,c1) ORDER_PP_CAT(c0(ORDER_PP_SELECT_4_,8true,8false),c1(,8true,8false))
#define ORDER_PP_SELECT_4_8true8true(P,tt,tf,ft,...) P##tt
#define ORDER_PP_SELECT_4_8true8false(P,tt,tf,ft,...) P##tf
#define ORDER_PP_SELECT_4_8false8true(P,tt,tf,ft,...) P##ft
#define ORDER_PP_SELECT_4_8false8false(P,tt,tf,ft,...) P##__VA_ARGS__

#define ORDER_PP_SAME(P,x,y) ORDER_PP_TEST(ORDER_PP_IF_,ORDER_PP_SYM_##x##_##y(,),8true,8false)
#define ORDER_PP_NOT_SAME(P,x,y) ORDER_PP_TEST(ORDER_PP_IF_,ORDER_PP_SYM_##x##_##y(,),8false,8true)

#define ORDER_PP_IS_EDIBLE(P,x) ORDER_PP_TEST(ORDER_PP_IF_,ORDER_PP_IS_EDIBLE_TEST x##P,8true,8false)
#define ORDER_PP_IS_NOT_EDIBLE(P,x) ORDER_PP_TEST(ORDER_PP_IF_,ORDER_PP_IS_EDIBLE_TEST x##P,8false,8true)
#define ORDER_PP_IS_EDIBLE_TEST(...) ,,

#define ORDER_PP_IS_SYM(P,x) ORDER_PP_IS_EDIBLE(,P##x)(,ORDER_PP_IF_8false ORDER_EAT,ORDER_PP_IS_SYM_NOT_EDIBLE)(P##x)
#define ORDER_PP_IS_SYM_NOT_EDIBLE(x) ORDER_PP_TEST(ORDER_PP_IF_,ORDER_PP_SYM_##x##_##x(,),8true,8false)

#define ORDER_PP_IS_NIL(P,x) ORDER_PP_IS_EDIBLE(,P##x)(,ORDER_PP_IF_8false ORDER_PP_EAT,ORDER_PP_IS_NIL_NOT_EDIBLE)(P##x)
#define ORDER_PP_IS_NIL_NOT_EDIBLE(x) ORDER_PP_TEST(ORDER_PP_IF_,ORDER_PP_IS_NIL_##x,8true,8false)
#define ORDER_PP_IS_NIL_ ,,

#define ORDER_PP_TEST(P,x,c,a) ORDER_PP_TEST_B(,x,P##c,,P##a,)
#define ORDER_PP_TEST_B(P,_1,_2,_3,x,...) x##P

#endif
