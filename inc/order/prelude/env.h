// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.

#define ORDER_PP_DEF_8env_bind ORDER_PP_FN_NATIVE(3,9ENV_BIND,0IS_SYM,0IS_ENV,0IS_ANY)
#define ORDER_PP_9ENV_BIND(P,s,e,v) (,P##s,P##v)P##e

#define ORDER_PP_DEF_8env_nil 8DEF_CONST,,

#define ORDER_PP_DEF_8env_ref ORDER_PP_FN_NATIVE(2,9ENV_REF,0IS_SYM,0IS_ENV_CONS)

#define ORDER_PP_DEF_8env_to_seq_of_pairs ORDER_PP_FN_CM(1,8ENV_TO_SEQ_OF_PAIRS,0IS_ENV)
#define ORDER_PP_8ENV_TO_SEQ_OF_PAIRS(P,e,...) (,ORDER_PP_SEQ_TERMINATE(ORDER_PP_ENV_TO_SEQ_OF_PAIRS_A P##e),P##__VA_ARGS__)
#define ORDER_PP_ENV_TO_SEQ_OF_PAIRS_A(P,s,v) ((P##s,P##v))ORDER_PP_ENV_TO_SEQ_OF_PAIRS_B
#define ORDER_PP_ENV_TO_SEQ_OF_PAIRS_A0
#define ORDER_PP_ENV_TO_SEQ_OF_PAIRS_B(P,s,v) ((P##s,P##v))ORDER_PP_ENV_TO_SEQ_OF_PAIRS_A
#define ORDER_PP_ENV_TO_SEQ_OF_PAIRS_B0

#define ORDER_PP_DEF_8seq_of_pairs_to_env ORDER_PP_FN_CM(1,8SEQ_OF_PAIRS_TO_ENV,0IS_SEQ)
#define ORDER_PP_8SEQ_OF_PAIRS_TO_ENV(P,s,...) (,ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_OF_PAIRS_TO_ENV_A P##s),P##__VA_ARGS__)
#define ORDER_PP_SEQ_OF_PAIRS_TO_ENV_A(p) (,ORDER_PP_REM p)ORDER_PP_SEQ_OF_PAIRS_TO_ENV_B
#define ORDER_PP_SEQ_OF_PAIRS_TO_ENV_A0
#define ORDER_PP_SEQ_OF_PAIRS_TO_ENV_B(p) (,ORDER_PP_REM p)ORDER_PP_SEQ_OF_PAIRS_TO_ENV_A
#define ORDER_PP_SEQ_OF_PAIRS_TO_ENV_B0

// Detail

#define ORDER_PP_0IS_ENV(P,x) ORDER_PP_OR(or)(ORDER_PP_0IS_ENV_CONS(,P##x))(or)(ORDER_PP_IS_NIL(,P##x))()
#define ORDER_PP_0IS_ENV_CONS(P,x) ORDER_PP_AND(and)(ORDER_PP_IS_EDIBLE(,P##x))(and)(ORDER_PP_FX(IS_TUPLE_SIZE_2,(ORDER_PP_REM P##x)))()
