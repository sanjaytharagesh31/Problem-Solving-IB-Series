vector<string> Solution::fizzBuzz(int A) {
    vector<string> str;
    for(int i=1; i<=A; i++ ){
        if(i%3==0 && i%5==0)
            str.push_back("FizzBuzz");
        else if(i%3 == 0)
            str.push_back("Fizz");
        else if(i%5 == 0)
            str.push_back("Buzz");
        else
            str.push_back(to_string(i));
    }
    return str;
}
