enum DAY
{
    MON=1, TUE, WED, THU, FRI, SAT, SUN
}
/*等价于
#define MON  1
#define TUE  2
#define WED  3
#define THU  4
#define FRI  5
#define SAT  6
#define SUN  7*/
/*第一个枚举成员的默认值为整型的 0，后续枚举成员的值在前一个成员上加 1。
我们在这个实例中把第一个枚举成员的值定义为 1，第二个就为 2，以此类推。*/