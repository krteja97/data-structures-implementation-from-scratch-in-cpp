#python for result comparision
import numpy as np;

s1cr = 25;
s2cr = 23;
s3cr = 22;
s4cr = 23;
s5cr = 24;

total_credits = s1cr + s2cr + s3cr + s4cr + s5cr + 22;

s1g = 8.24;
s2g = 8.87
s3g = 9.32
s4g = 9.61;
s5g = 9.42;

sem4count = s1cr*s1g + s2cr*s2g + s3cr*s3g + s4cr*s4g + s5cr*s5g;

# for x in np.arange(7,10,0.04):
# 	tcredit = x*s5cr + (sem4count);
# 	print(x,tcredit/total_credits);

s5cg = 9.00;

for x in np.arange(8.0,10,0.01):
	print(x,(sem4count + 22*x )/total_credits);

print(sem4count/117)


