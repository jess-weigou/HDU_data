package 集合和泛型;

import java.util.ArrayList;
import java.util.List;

public class employee{
    public static void main(String[] args) {

        List<Employee> al = new ArrayList<Employee>();
        al.add(new Employee("1001", "Tom", "Market", 1200));
        al.add(new Employee("1002", "Jack", "Department", 1300));
        al.add(new Employee("1003", "Simth", "Market", 2000));
        al.add(new Employee("1004", "Tony", "Department", 3000));
        //print thr emp's name and salary
        for(int i=0; i<al.size(); i++){
            System.out.println(al.get(i));
        }
        //output the salary of jack
        for(int i=0; i<al.size(); i++){
            if(al.get(i).getEname().equals("Jack")){
                al.get(i).changePay(1500);
            }
        }
        double salary = 0;
        for(int i=0; i<al.size(); i++){
            salary += al.get(i).getEsal();
            al.get(i).changePay(0.2);
        }
        System.out.println("平均工资为: "+salary/al.size());
        //remove the name Tom
        for(int i=0; i<al.size(); i++){
            if(al.get(i).getEname().equals("Tom")){
                al.remove(i);
            }
        }
    }
}
class Employee{
    private String eid;
    private String ename;
    private String edept;
    private double esal;
    public Employee(String a,String b,String c,double d){
        eid = a;
        ename = b;
        edept = c;
        esal = d;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "eid='" + eid + '\'' +
                ", ename='" + ename + '\'' +
                ", edept='" + edept + '\'' +
                ", esal=" + esal +
                '}';
    }
    public  String getEname(){
        return ename;
    }
    public double getEsal(){
        return esal;
    }
    public void changePay(int a){
        this.esal = a;
    }
    public void changePay(double b){
        this.esal *= b;
    }
}