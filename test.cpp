#include <iostream>
#include <stack>
using namespace std;
typedef unsigned int uint32_t;

int main(){
	uint32_t n = 43261596;
	stack<int> st;
    uint32_t tmp1 = 1;
    for (int i = 0; i < 32; i++){
    	cout<<(tmp1&n)<<endl;
        if (tmp1 & n){
        	st.push(1);
        }else{
            st.push(0);
        }
        tmp1 << 1;
    }
    uint32_t tmp2 = 1;
    uint32_t res = 0;
    while(!st.empty()){
        int stpop = st.top();
        //cout<<stpop<<endl;
        if (stpop == 1){
            res &= tmp2;
            tmp2 << 1;
        }else{
            tmp2 << 1;
        }
        st.pop();
    }
	
	return 0;
}
