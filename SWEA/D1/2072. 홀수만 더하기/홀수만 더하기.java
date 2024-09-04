import java.util.Scanner;

public class Solution {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        for(int i=0; i<T; i++){
            int sum = 0;
            for(int j=0; j<10; ++j){
                int x = sc.nextInt();
                if(x%2!=0)
                    sum+=x;
            }

            System.out.println("#"+(i+1)+" "+sum);
        }
    }
}
