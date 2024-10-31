p=-1
for i in zip(*[map(int,x.split())for x in open(0)][1:]):p<max(i)or(print('NO'),exit());p=max(p+1,min(i))
print('YES')