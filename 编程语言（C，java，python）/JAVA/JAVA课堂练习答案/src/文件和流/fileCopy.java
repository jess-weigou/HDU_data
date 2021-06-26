package 文件和流;
import java.io.*;
import java.util.Scanner;

public class fileCopy {
    public static void main(String[] args) {
        String s;
        File f = new File("text.txt");
        FileReader fr = null;
        FileWriter fw = null;
        Scanner sc = new Scanner(System.in);
        try{
//            FileInputStream fis = new FileInputStream(f);
//            FileOutputStream fos = new FileOutputStream("copy.txt");
            s = sc.nextLine();
            fr = new FileReader(s);
            fw = new FileWriter(s+"_copy.txt");
            char []b = new char[(int)f.length()];
            System.out.printf("%d%d",1,2);
            fr.read(b);
            fw.write(b);

        } catch(IOException e){
            System.out.println(e.toString());
        } finally {
//            fis.close();
//            fos.close();
            try {
                if(fr != null){
                    fr.close();
                }
            }catch (IOException ignored){

            }

            try {
                if(fw != null){
                    fw.close();
                }
            }catch (IOException ignored){

            }

        }
    }
}