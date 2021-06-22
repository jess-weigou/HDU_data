package 异常处理;

import java.util.Scanner;

class  TestExceptions2 {
    static void checkEmail(String s) throws postboxException, nonePostboxException {
        int flag =0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='@'){
                if( i < 6 ){
                    throw new postboxException("前缀太短");
                }else{
                    flag = 1;
                }
            }
        }
        if(flag ==0){
            throw  new nonePostboxException("无@");
        }
    }
    public static void main(String[] args) throws postboxException, nonePostboxException {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        checkEmail(s);
    }
}
class postboxException extends Exception {
    postboxException(String s) {
        super(s);
    }
}
class nonePostboxException extends  Exception{
    nonePostboxException(String s){
        super(s);
    }
}