mod = 998244353
_as = [1, 1, 1] + [0] * 600

for i in range(3, 601):
    _as[i] = _as[i - 1] * 2

p = 1

ans = 0

n = int(input())

while n > 0:
    _as[p]<=n:
        n-=_as[p]
        ans+=p*_as[p]
    else:
        ans+=n*p
        n=0
    ans%=mod
    p+=1

print(ans % mod)
