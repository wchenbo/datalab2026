/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return  ~(~x|~y);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return ~(~x&~y)&~(x&y);
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x,int y){
    int X=x>>31;
    int Y=y>>31;
    int sameSign=!(X^Y);
    int xzero=!x;
    int yzero=!y;
    if(xzero&&yzero)
        return 1;
    return sameSign&&(!xzero)&&(!yzero);
}
/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int res=0;
    int s;
    s=(v>0xFFFF)<<4;
    res=res|s;
    v=v>>s;
    s=(v>0xFF)<<3;
    res=res|s;
    v=v>>s;
    s=(v>0xF)<<2;
    res=res|s;
    v=v>>s;
    s=(v>0x3)<<1;
    res=res|s;
    v=v>>s;
    s=(v>0x1)<<0;
    res=res|s;
    return res;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x,int n,int m){
    int sn=n<<3,sm=m<<3;
    int bn=(x>>sn)&0xFF,bm=(x>>sm)&0xFF;
    return (x&~((0xFF<<sn)|(0xFF<<sm)))|(bn<<sm)|(bm<<sn);
}
/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v){
v=((v>>1)&0x55555555)|((v<<1)&0xAAAAAAAA);
v=((v>>2)&0x33333333)|((v<<2)&0xCCCCCCCC);
v=((v>>4)&0x0F0F0F0F)|((v<<4)&0xF0F0F0F0);
v=((v>>8)&0x00FF00FF)|((v<<8)&0xFF00FF00);
v=((v>>16)|(v<<16));
return v;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int arith=x>>n;
    int mask=((1<<31)>>n)<<1;
    mask=~mask;
    return arith&mask;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int cnt=0;
    int t;
    int a=x;
    t=!((x&(0xFFFF<<16))^(0xFFFF<<16));
    cnt+=t<<4;
    x=x<<(t<<4);
    t=!((x&(0xFF<<24))^(0xFF<<24));
    cnt+=t<<3;
    x=x<<(t<<3);
    t=!((x&(0xF<<28))^(0xF<<28));
    cnt+=t<<2;
    x=x<<(t<<2);
    t=!((x&(0x3<<30))^(0x3<<30));
    cnt+=t<<1;
    x=x<<(t<<1);
    t=!((x&(0x1<<31))^(0x1<<31));
    cnt+=t;
    x=x<<t;
    int allOne=!(a^(~0));
    cnt=cnt+allOne;
    return cnt;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned s, e, m;
    unsigned absX = x;
    if(!x) return 0;
    if(x==0x80000000) return 0xCF000000;
    s=0;
    if(x<0){
        s=0x80000000;
        absX=-x;
    }
    unsigned bitPos=31;
    while(!(absX&(1U<<bitPos)))bitPos=bitPos - 1;
    e=bitPos+127;
    if(bitPos>23){
        unsigned shift=bitPos-23;
        unsigned roundBits=absX&((1U<<shift)-1);
        m=absX>>shift;
        unsigned halfBit=1U<<(shift-1);
        if(roundBits>halfBit){
            m=m+1;
        }else{
            if(roundBits==halfBit){
                if(m&1){
                    m=m+1;
                }
            }
        }
        if(m&0x1000000){
            e=e+1;
            m=0;
        }
    }else{
        m=absX<<(23-bitPos);
    }
    return s|(e<<23)|(m&0x7FFFFF);
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned s,e,m;
    s=uf&(1U<<31);
    e=uf&(0xFFU<<23);
    m=uf&(0x7FFFFFU);
    if((e|0x00000000U)==0x00000000U)
    {   if(((e|m)|0x00000000U)==0x00000000U)
        {
return uf;
        }
        else
        {
            return (s|e|m<<1);
        }
    }
    else if((e|0x00000000U)==0x7F800000U)
    {
        return uf;
    }
    else
    {
        if(((e|m)|0x00000000U)==0x7E000000U)
        {
            return (s|0x7F800000U|0x00000000);
        }
        else
        {
            return (s|(e+(1U<<23))|m);
        }
    }
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned s=uf2&(1U<<31);
    unsigned e=uf2&(0x7FF00000U);
    e=e>>20;
    if(!e)return 0;
    if(e>=0x7FFU){
        if(e<=0x7FFU){
            return 0x80000000;
        }
    }
    int exp=e-1023;
    if(exp<0)return 0;
    if(exp>=31)return 0x80000000;
    unsigned h=uf2&0xFFFFFU;
    unsigned l=uf1;
    unsigned k=52U-exp;
    unsigned xx;
    if(k>32U){
        xx=(1U<<(52U-k))|(h>>(k-32U));
    }else{
        unsigned high=1U<<(52U-k);
        unsigned low=(h<<(32U-k))|(l>>k);
        xx=low|(high<<(32U-k));
    }
    if(!s){
        return xx;
    }else{
        return -xx;
    }
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    if(x>=128)
    {
        return 0x7F800000;
    }
    else if(x>=-126&&x<128)
    {
        return (x+127)<<23;
    }
    else if(x<-149)
    {
        return 0;
    }
    else
    {
        return 1<<(x+149);
    }
}
