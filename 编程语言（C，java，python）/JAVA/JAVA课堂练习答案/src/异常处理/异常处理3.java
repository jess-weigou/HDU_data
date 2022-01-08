package 异常处理;
import java.util.Scanner;
class TestExceptions1 {
    public static void main(String[] arg)  {
        Scanner sc = new Scanner(System.in);
        while (true){
            try {
                int num;
                if (sc.hasNextInt()){
                     num = sc.nextInt();
                }else{
                    sc.nextLine();
                    throw new ErrorInputException("非法输入");
                }
                if(num <100){
                    throw  new Exception100("不超过100");
                }else if(num >1000){
                    throw  new Exception1000("超过1000");
                }else{
                    System.out.println("数字正常");
                    break;
                }
            }catch (Exception100 e){
                System.out.println(e.toString());
            }catch (Exception1000 e){
                System.out.println(e.toString());
            } catch (ErrorInputException e) {
                System.out.println(e.toString());
            }
        }
    }
}
class Exception100 extends Exception{
    Exception100(String str){
        super(str);
    }
}
class Exception1000 extends Exception{
    Exception1000(String str){
        super(str);
    }
}
class ErrorInputException extends Exception{
    ErrorInputException(String str){
        super(str);
    }
}




