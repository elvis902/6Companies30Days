	/* Program to find Nth Ugly Number
	https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/#
	 */




	unsigned long long getNthUglyNo(int n) {
	    vector<unsigned long long>v(n+1);
	    v[1] = 1;
	    int t2 = 1, t3 = 1, t5 = 1;
	    for(int i = 2; i <= n; i++)
	    {
	        unsigned long long n2 = 2*v[t2], n3 = 3*v[t3], n5 = 5*v[t5];
	        unsigned long long n = n2 < n3 ? n2 : n3;
	        n = n5 < n ? n5 : n;
	        
	        if(n2 == n) t2++;
	        if(n3 == n) t3++;
	        if(n5 == n) t5++;
	        
	        v[i] = n;
	    }
	    return v[n];
	}