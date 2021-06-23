package 文件和流;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.Date;

public class 文件和流1 {
    public static void main(String[] args) throws IOException {


        byte b[] = {'H','e','l','l','o','W','o','r','l','d'};
        byte b1[] = new byte[20];
        File file = new File("text.txt");
        FileOutputStream fileOutputStream = null;
        FileInputStream fileInputStream = null;
        try {
            fileInputStream = new FileInputStream(file);
            //check if the file exits
            if (file.exists()){
                fileOutputStream = new FileOutputStream(file,true);;
            }else{
                fileOutputStream = new FileOutputStream(file);;
            }

            fileOutputStream.write(b);
            fileInputStream.read(b1);
            System.out.println(Arrays.toString(b1));

        }catch (IOException e){
            System.out.println(e);
        }
        finally{
            try {
                if (fileInputStream !=null)
                    fileInputStream.close();
            }catch (IOException e){
                System.out.println(e.toString());
            }
            try {
                if (fileOutputStream != null){
                    fileOutputStream.close();
                }
            }catch (IOException e){
                System.out.println(e.toString());
            }

        }




    }
}
