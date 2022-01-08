class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& row, vector<int>& col) {
        int r = row.size();
        int c = col.size();
        int sr = startPos[0];
        int sc = startPos[1];
        int dr = homePos[0];
        int dc = homePos[1];
        
        if(dr > sr && dc > sc){
            /// right -  niche
            int ans = 0;
            while(sr < dr){
                sr+=1;
                ans+=row[sr];
            }
            while(sc < dc){
                sc+=1;
                ans+=col[sc];
            }
            return ans;
        }
        else if(dr < sr && dc > sc){
            //// right - upar
            
            int ans = 0;
            while(sr > dr){
                sr-=1;
                ans+=row[sr];
            }
            while(sc < dc){
                sc+=1;
                ans+=col[sc];
            }
            return ans;
            
        }
        else if(dr > sr && dc < sc ){
            //// left- niche
            
            int ans = 0;
            while(sr < dr){
                sr+=1;
                ans+=row[sr];
            }
            while(sc > dc){
                sc-=1;
                ans+=col[sc];
            }
            return ans;
            
            
            
        }
        else if(dr < sr && dc < sc ){
            // left - upar
            
            int ans = 0;
            while(sr > dr){
                sr-=1;
                ans+=row[sr];
            }
            while(sc > dc){
                sc-=1;
                ans+=col[sc];
            }
            return ans;
            
            
        }
        else if(dc == sc && dr == sr){
            return 0;
        }
        else if(dc == sc && dr < sr  ){
            // straight up 
            int ans = 0;
            while(sr > dr){
                sr-=1;
                ans+=row[sr];
            }
            // while(sc < dc){
            //     sc+=1;
            //     ans+=col[sc];
            // }
            return ans;
            
            
            
        }
        else if( dc == sc && dr > sr ){
            // down
            
            
                        int ans = 0;
            while(sr < dr){
                sr+=1;
                ans+=row[sr];
            }
            // while(sc < dc){
            //     sc+=1;
            //     ans+=col[sc];
            // }
            return ans;
        }
        else if( dr == sr && dc < sc ){
            // left
            
            
            int ans = 0;
            
            while(sc > dc){
                sc-=1;
                ans+=col[sc];
            }
            return ans;
        }
        else if( dr == sr && dc > sc ){
            int ans = 0;
         
            while(sc < dc){
                sc+=1;
                ans+=col[sc];
            }
            return ans;
        }
        
        return 0 ;
    }
};