int cmmdc(int a, int b)
{
    if (b == 0) return a;
    int r;
    r = a % b;
    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}


