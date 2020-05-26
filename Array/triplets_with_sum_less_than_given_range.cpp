int Solution::solve(vector<string> &A) {
    vector<float> v(A.size());
    for(int i=0; i<A.size(); i++)
        v[i] = stof(A[i]);
    float a,b,c;
    a = v[0];
    b = v[1];
    c = v[2];
    for(int i=3;i<A.size();i++) {
        if((a+b+c)>1 && (a+b+c)<2)
            return 1;
        else if((a+b+c)>=2) {
            if(a>b && a>c)
                a=v[i];
            else if(b>a && b>c)
                b=v[i];
            else
                c=v[i];
        }
        else {
            if(a<b && a<c)
                a=v[i];
            else if(b<a && b<c)
                b=v[i];
            else
                c=v[i];
        }
    }
    
    if((a+b+c)>1 && (a+b+c)<2)
        return 1;
    
    return 0;
}
