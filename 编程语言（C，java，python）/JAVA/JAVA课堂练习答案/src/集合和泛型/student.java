package 集合和泛型;

import java.util.ArrayList;
import java.util.List;

public class student {
    public static void main(String[] args) {
        List<Student> st = new ArrayList<Student>();
        st.add(new Student(1,"Tom",20));
        st.add(new Student(2,"Jack",21));
        st.add(new Student(3,"John",22));
        st.add(new Student(4,"Tom",20));
        st.add(new Student(5,"John",22));
        //remove duplicate
        for(int i=0; i<st.size()-1;i++){
            for(int j=i+1; j< st.size();j++){
                if(st.get(i).getName().equals(st.get(j).getName())){
                    if (st.get(i).getAge() == st.get(j).getAge()){
                        st.remove(j);
                    }
                }
            }
        }
        for (int i=0; i<st.size(); i++){
            st.get(i).changeId(i+1);
            System.out.println(st.get(i).toString());
        }
    }
}

class Student{
    private  int id;
    private  String name;
    private  int age;
    Student(int a, String c, int b){
        this.id = a;
        this.name = c;
        this.age = b;
    }
    public String getName(){
        return name;
    }
    public  int getAge(){
        return age;
    }
    public void changeId(int id){
        this.id = id;
    }

    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}