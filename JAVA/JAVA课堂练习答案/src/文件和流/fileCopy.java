package 文件和流;
import java.io.*;
import java.util.Scanner;

public class fileCopy {
    public static void main(String[] args) {
        String s[] ;
        //String s;
        File f = new File("text.txt");
        FileReader fr = null;
        FileWriter fw = null;
        BufferedWriter bw = null;
        BufferedReader br  = null;
        Scanner sc = new Scanner(System.in);
        try{
            char []b = new char[(int)f.length()];
            fr = new FileReader(f);
            br = new BufferedReader(fr);
            fw = new FileWriter(f);
            bw =  new BufferedWriter(fw);
            int pay = 0,income = 0;
            while (br.read() != -1){
                s = br.readLine().split(",");
                System.out.println(br.readLine());
                System.out.println(s);
                if(s[2] == "收入" ){
                    income += Integer.parseInt(s[4]);
                }else if(s[2] == "支出"){
                    pay += Integer.parseInt(s[4]);
                }
            }
            System.out.println(pay);
            System.out.println(income);


        }catch(FileNotFoundException e){
            System.out.println(e.toString());
        }catch (IOException e){
            System.out.println(e.toString());
        }finally {
            try {
                if(fr != null){

                    fr.close();
                }
            }catch (IOException e){

            }

            try {
                if(fw != null){
                    fw.close();
                }
            }catch (IOException e){

            }

        }
    }
}
