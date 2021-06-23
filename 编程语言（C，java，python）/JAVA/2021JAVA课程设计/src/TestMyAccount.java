

import java.io.*;
import java.util.*;

public class TestMyAccount {
    public static void main(String[] args) {
        ArrayList<MyAccount> a1=new ArrayList<MyAccount>();
        a1.add(new MyAccount("1","2019-12-12","收入","工资","8000"));
        a1.add(new MyAccount("2","2019-12-13","支出","购物","1000"));
        a1.add(new MyAccount("3","2019-12-14","收入","奖金","5000"));
        a1.add(new MyAccount("4","2019-12-15","支出","餐饮","80"));
        a1.add(new MyAccount("5","2019-12-15","支出","购物","100"));
        try {
            FileOutputStream fos=new FileOutputStream("xu.txt");
            ObjectOutputStream oos=new ObjectOutputStream(fos);
            oos.writeObject(a1);
            oos.close();
            fos.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
class MyAccount implements Serializable{
    private String id;
    private String date;
    private String type;
    private String content;
    private String amount;
    public MyAccount(String id, String date, String type, String content, String amount) {
        super();
        this.id = id;
        this.date = date;
        this.type = type;
        this.content = content;
        this.amount = amount;
    }
    public String getId() {
        return id;
    }
    public void setId(String id) {
        this.id = id;
    }
    public String getDate() {
        return date;
    }
    public void setDate(String date) {
        this.date = date;
    }
    public String getType() {
        return type;
    }
    public void setType(String type) {
        this.type = type;
    }
    public String getContent() {
        return content;
    }
    public void setContent(String content) {
        this.content = content;
    }
    public String getAmount() {
        return amount;
    }
    public void setAmount(String amount) {
        this.amount = amount;
    }

}



