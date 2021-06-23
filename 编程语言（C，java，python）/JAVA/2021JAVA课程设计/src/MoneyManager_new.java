
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Objects;
import java.util.regex.Pattern;

public class MoneyManager_new {
    public static void main(String[] args) {
        LoginFrame lf=new LoginFrame();
        lf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

//登录界面
class LoginFrame extends JFrame implements ActionListener {
    private JLabel l_user,l_pwd; //用户名标签，密码标签
    private JTextField t_user;//用户名文本框
    private JPasswordField t_pwd; //密码文本框
    private JButton b_ok,b_cancel; //登录按钮，退出按钮

    public LoginFrame(){
        super("欢迎使用个人理财账本!");
        l_user=new JLabel("用户名：",JLabel.RIGHT);
        l_pwd=new JLabel(" 密码：",JLabel.RIGHT);
        t_user=new JTextField(30);
        t_pwd=new JPasswordField(30);
        b_ok=new JButton("登录");
        b_cancel=new JButton("退出");
        //布局方式FlowLayout，一行排满排下一行
        Container c=this.getContentPane();
        c.setLayout(new FlowLayout());
        c.add(l_user);
        c.add(t_user);
        c.add(l_pwd);
        c.add(t_pwd);
        c.add(b_ok);
        c.add(b_cancel);
        //为按钮添加监听事件
        b_ok.addActionListener(this);
        b_cancel.addActionListener(this);
        //界面大小不可调整
        this.setResizable(false);
        this.setSize(400,150);

        //界面显示居中
        Dimension screen = this.getToolkit().getScreenSize();
        this.setLocation((screen.width-this.getSize().width)/2,(screen.height-this.getSize().height)/2);
        this.show();
    }
    //验证账号密码
    public void actionPerformed(ActionEvent e) {
        if(b_cancel==e.getSource()){
            //添加退出代码 ok
            System.exit(0);
            //
        }else if(b_ok==e.getSource()){
            //添加代码，验证身份成功后显示主界面ok
            try {
                FileReader f=new FileReader("/home/david/Desktop/大二第二学期/JAVA/2021JAVA课程设计/pwd.txt");
                BufferedReader b1=new BufferedReader(f);
                String s=b1.readLine();
                boolean flag=false;
                if(t_user.getText().trim().equals("123")&&t_pwd.getText().equals(s)) {
                    new MainFrame(t_user.getText().trim());
                    flag=true;
                }
                else {
                    flag=false;
                }
                if(flag==false) {
                    JOptionPane.showMessageDialog(null,"用户名密码出错", "警告", JOptionPane.ERROR_MESSAGE);
                }
            }catch (FileNotFoundException e1) {
                e1.printStackTrace();
            } catch(IOException e1) {
                e1.printStackTrace();
            }catch (Exception e1) {
                e1.printStackTrace();
            }
        }
    }
}

//主界面
class MainFrame extends JFrame implements ActionListener{
    private JMenuBar mb=new JMenuBar();
    private JMenu m_system=new JMenu("系统管理");
    private JMenu m_fm=new JMenu("收支管理");
    private JMenuItem mI[]={new JMenuItem("密码重置"),new JMenuItem("退出系统")};
    private JMenuItem m_FMEdit=new JMenuItem("收支编辑");
    private JLabel l_type,l_fromdate,l_todate,l_bal,l_ps;
    private JTextField t_fromdate,t_todate;
    private JButton b_select1,b_select2;
    private JComboBox<String> c_type;
    private JPanel p_condition,p_detail;
    private String s1[]={"收入","支出"};
    private double bal1,bal2;
    private JTable table;
    private String username;
    //主界面构造函数
    public MainFrame(String username) throws IOException {
        super(username+",欢迎使用个人理财账本!");
        this.username=username;
        Container c=this.getContentPane();
        c.setLayout(new BorderLayout());
        c.add(mb,"North");
        mb.add(m_system);
        mb.add(m_fm);
        m_system.add(mI[0]);
        m_system.add(mI[1]);
        m_fm.add(m_FMEdit);
        m_FMEdit.addActionListener(this);
        mI[0].addActionListener(this);
        mI[1].addActionListener(this);

        l_type=new JLabel("收支类型：");
        c_type=new JComboBox<>(s1);
        b_select1=new JButton("查询");
        l_fromdate=new JLabel("起始时间");
        t_fromdate=new JTextField(8);
        l_todate=new JLabel("终止时间");
        t_todate=new JTextField(8);
        b_select2=new JButton("查询");
        l_ps = new JLabel("注意：时间格式为YYYYMMDD，例如：20150901");
        p_condition=new JPanel();
        p_condition.setLayout(new GridLayout(3,1));
        p_condition.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createTitledBorder("输入查询条件"),
                BorderFactory.createEmptyBorder(5,5,5,5)));

        JPanel p1 = new JPanel();
        JPanel p2 = new JPanel();
        JPanel p3 = new JPanel();
        p1.add(l_type);
        p1.add(c_type);
        p1.add(b_select1);
        p2.add(l_fromdate);
        p2.add(t_fromdate);
        p2.add(l_todate);
        p2.add(t_todate);
        p2.add(b_select2);
        p3.add(l_ps);
        p_condition.add(p1);
        p_condition.add(p2);
        p_condition.add(p3);
        c.add(p_condition,"Center");

        b_select1.addActionListener(this);
        b_select2.addActionListener(this);

        p_detail=new JPanel();
        p_detail.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createTitledBorder("收支明细信息"),
                BorderFactory.createEmptyBorder(5,5,5,5)));
        l_bal=new JLabel();
        String[] cloum = {"编号", "日期", "类型","内容","金额",};
        Object[][] row = new Object[50][5];
        table = new JTable(row, cloum);
        JScrollPane scrollpane = new JScrollPane(table);
        scrollpane.setPreferredSize(new Dimension(580,350));
        scrollpane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scrollpane.setViewportView(table);
        p_detail.add(l_bal);
        p_detail.add(scrollpane);
        c.add(p_detail,"South");

        //添加代码
        //主界面显示
        method m=new method();
        m.showDetail(row);
        //
        bal1=0;
        double b;
        ArrayList<MyAccount> a1=new ArrayList<MyAccount>();
        a1=m.loadList(a1);
        for(int i=0;i<a1.size();i++) {
            b=Double.parseDouble(a1.get(i).getAmount());
            if(a1.get(i).getType().equals("收入")) {
                bal1+=b;
            }else {
                bal1-=b;
            }
        }
        if(bal1<0)
            l_bal.setText("个人总收支余额为"+bal1+"元。您已超支，请适度消费！");
        else
            l_bal.setText("个人总收支余额为"+bal1+"元。");

        this.setResizable(false);
        this.setSize(600,580);
        Dimension screen = this.getToolkit().getScreenSize();
        this.setLocation((screen.width-this.getSize().width)/2,(screen.height-this.getSize().height)/2);
        this.show();
    }
    //主界面构造函数重载
    public MainFrame(String username,ArrayList<MyAccount> a1){
        super(username+",欢迎使用个人理财账本!");
        this.username=username;
        Container c=this.getContentPane();
        c.setLayout(new BorderLayout());
        c.add(mb,"North");
        mb.add(m_system);
        mb.add(m_fm);
        m_system.add(mI[0]);
        m_system.add(mI[1]);
        m_fm.add(m_FMEdit);
        m_FMEdit.addActionListener(this);
        mI[0].addActionListener(this);
        mI[1].addActionListener(this);

        l_type=new JLabel("收支类型：");
        c_type=new JComboBox<>(s1);
        b_select1=new JButton("查询");
        l_fromdate=new JLabel("起始时间");
        t_fromdate=new JTextField(8);
        l_todate=new JLabel("终止时间");
        t_todate=new JTextField(8);
        b_select2=new JButton("查询");
        l_ps = new JLabel("注意：时间格式为YYYYMMDD，例如：20150901");
        p_condition=new JPanel();
        p_condition.setLayout(new GridLayout(3,1));
        p_condition.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createTitledBorder("输入查询条件"),
                BorderFactory.createEmptyBorder(5,5,5,5)));

        JPanel p1 = new JPanel();
        JPanel p2 = new JPanel();
        JPanel p3 = new JPanel();
        p1.add(l_type);
        p1.add(c_type);
        p1.add(b_select1);
        p2.add(l_fromdate);
        p2.add(t_fromdate);
        p2.add(l_todate);
        p2.add(t_todate);
        p2.add(b_select2);
        p3.add(l_ps);
        p_condition.add(p1);
        p_condition.add(p2);
        p_condition.add(p3);
        c.add(p_condition,"Center");

        b_select1.addActionListener(this);
        b_select2.addActionListener(this);

        p_detail=new JPanel();
        p_detail.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createTitledBorder("收支明细信息"),
                BorderFactory.createEmptyBorder(5,5,5,5)));
        l_bal=new JLabel();
        String[] cloum = {"编号", "日期", "类型","内容","金额",};
        Object[][] row = new Object[50][5];
        table = new JTable(row, cloum);
        JScrollPane scrollpane = new JScrollPane(table);
        scrollpane.setPreferredSize(new Dimension(580,350));
        scrollpane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scrollpane.setViewportView(table);
        p_detail.add(l_bal);
        p_detail.add(scrollpane);
        c.add(p_detail,"South");

        //添加代码
        //主界面显示
        method m=new method();
        m.showDetail(row, a1);
        //
        bal1=0;
        double b;
        a1=m.loadList(a1);
        for(int i=0;i<a1.size();i++) {
            b=Double.parseDouble(a1.get(i).getAmount());
            if(a1.get(i).getType().equals("收入")) {
                bal1+=b;
            }else {
                bal1-=b;
            }
        }
        if(bal1<0)
            l_bal.setText("个人总收支余额为"+bal1+"元。您已超支，请适度消费！");
        else
            l_bal.setText("个人总收支余额为"+bal1+"元。");

        this.setResizable(false);
        this.setSize(600,580);
        Dimension screen = this.getToolkit().getScreenSize();
        this.setLocation((screen.width-this.getSize().width)/2,(screen.height-this.getSize().height)/2);
        this.show();
    }

    public void actionPerformed(ActionEvent e) {
        Object temp=e.getSource();
        if(temp==mI[0]){
            //密码重置
            new ModifyPwdFrame(username);
        }else if(temp==mI[1]){
            //添加代码
            //退出系统
            System.exit(0);
        }else if(temp==m_FMEdit){
            //收支编辑
            try {
                new BalEditFrame();
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
        }else if(temp==b_select1){  //根据收支类型查询
            //添加代码
            //删除原界面
            this.dispatchEvent(new WindowEvent(this,WindowEvent.WINDOW_CLOSING) );
            //创建方法类，获得数据
            method m=new method();
            ArrayList<MyAccount> a1=new ArrayList<MyAccount>();
            a1=m.loadList(a1);
            ArrayList<MyAccount> a2=new ArrayList<MyAccount>();//收入
            ArrayList<MyAccount> a3=new ArrayList<MyAccount>();//支出
            for (MyAccount myAccount : a1) {
                if (myAccount.getType().equals("收入")) {
                    a2.add(myAccount);
                } else {
                    a3.add(myAccount);
                }
            }
            if(Objects.requireNonNull(c_type.getSelectedItem()).toString().equals("收入")){
                new MainFrame("123",a2);
            }else {
                new MainFrame("123",a3);
            }
        }else if(temp==b_select2){   //根据时间范围查询
            //添加代码
            //删除原界面
            this.dispatchEvent(new WindowEvent(this,WindowEvent.WINDOW_CLOSING) );
            //添加方法类
            method m=new method();
            ArrayList<MyAccount> a1=new ArrayList<>();
            a1=m.loadList(a1);
            //按时间获得所需数据，并查询
            String from=t_fromdate.getText();
            String to=t_todate.getText();
            ArrayList<MyAccount> a2=new ArrayList<>();
            for (MyAccount myAccount : a1) {
                if (myAccount.getDate().compareTo(from) >= 0 && myAccount.getDate().compareTo(to) <= 0) {
                    a2.add(myAccount);
                }
            }
            new MainFrame("123",a2);
        }
    }
}


//修改密码界面
class ModifyPwdFrame extends JFrame implements ActionListener{
    private JLabel l_oldPWD,l_newPWD,l_newPWDAgain;
    private JPasswordField t_oldPWD,t_newPWD,t_newPWDAgain;
    private JButton b_ok,b_cancel;
    private String username;

    public ModifyPwdFrame(String username){
        super("修改密码");
        this.username=username;
        l_oldPWD=new JLabel("旧密码");
        l_newPWD=new JLabel("新密码：");
        l_newPWDAgain=new JLabel("确认新密码：");
        t_oldPWD=new JPasswordField(20);
        t_newPWD=new JPasswordField(20);
        t_newPWDAgain=new JPasswordField(18);
        b_ok=new JButton("确定");
        b_cancel=new JButton("取消");
        Container c=this.getContentPane();
        c.setLayout(new FlowLayout());
        c.add(l_oldPWD);
        c.add(t_oldPWD);
        c.add(l_newPWD);
        c.add(t_newPWD);
        c.add(l_newPWDAgain);
        c.add(t_newPWDAgain);
        c.add(b_ok);
        c.add(b_cancel);
        b_ok.addActionListener(this);
        b_cancel.addActionListener(this);
        this.setResizable(false);
        this.setSize(280,160);
        Dimension screen = this.getToolkit().getScreenSize();
        this.setLocation((screen.width-this.getSize().width)/2,(screen.height-this.getSize().height)/2);
        this.show();
    }

    public void actionPerformed(ActionEvent e) {
        if(b_cancel==e.getSource()){
            //添加代码
            //取消
            this.dispatchEvent(new WindowEvent(this,WindowEvent.WINDOW_CLOSING) );
        }else if(b_ok==e.getSource()){  //修改密码
            //添加代码
            //确定
            try {
                boolean judge=true;
                BufferedReader br=new BufferedReader(new FileReader("d:/io/pwd.txt"));
                String s= br.readLine();
                if(t_newPWD.getText().trim().equals(s)){
                    JOptionPane.showMessageDialog(null,"新密码与原密码一样", "警告", JOptionPane.ERROR_MESSAGE);
                    judge=false;
                }
                if(t_newPWDAgain.getText().trim().contentEquals(t_newPWD.getText())&&judge==true)
                {
                    PrintWriter p=new PrintWriter(new BufferedWriter(new FileWriter("d:/io/pwd.txt")));
                    p.println(t_newPWD.getPassword());
                    p.close();
                    JOptionPane.showMessageDialog(null, "修改密码成功","提醒",JOptionPane.INFORMATION_MESSAGE);
                    this.dispatchEvent(new WindowEvent(this,WindowEvent.WINDOW_CLOSING) );
                    System.exit(0);
                }else if(judge==true&&t_newPWDAgain.getText().trim().contentEquals(t_newPWD.getText())==false) {
                    JOptionPane.showMessageDialog(null,"两次新密码不一致！", "警告", JOptionPane.ERROR_MESSAGE);
                }
            } catch (Exception e1) {
                e1.printStackTrace();
            }
        }
    }
}

//收支编辑界面
class  BalEditFrame extends JFrame implements ActionListener{
    private final JTextField t_id, t_date, t_bal;
    private final JComboBox<String> c_type;
    private final JComboBox<String> c_item;
    private final JButton b_update,b_delete,b_select,b_new,b_clear; //按钮
    private final JTable table;   //表格

    //收支界面构造函数
    public BalEditFrame() throws IOException {
        super("收支编辑" );
        JLabel l_id = new JLabel("编号：");
        JLabel l_date = new JLabel("日期：");
        JLabel l_bal = new JLabel("金额：");
        JLabel l_type = new JLabel("类型：");
        //标签
        JLabel l_item = new JLabel("内容：");
         //格子长度为8
        t_id=new JTextField(8);
        t_date=new JTextField(8);
        t_bal=new JTextField(8);

        String[] s1 ={"收入","支出"};
        String[] s2 ={"购物","餐饮","居家","交通","娱乐","人情","工资","奖金","其他"};
        c_type=new JComboBox<>(s1);
        c_item=new JComboBox<>(s2);

        b_select=new JButton("查询");
        b_update=new JButton("修改");
        b_delete=new JButton("删除");
        b_new=new JButton("录入");
        b_clear=new JButton("清空");

        Container c=this.getContentPane();
        c.setLayout(new BorderLayout());

        JPanel p1 = new JPanel();
        p1.setLayout(new GridLayout(5,2,10,10));
        p1.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createTitledBorder("编辑收支信息"),
                BorderFactory.createEmptyBorder(5,5,5,5)));
        p1.add(l_id);
        p1.add(t_id);
        p1.add(l_date);
        p1.add(t_date);
        p1.add(l_type);
        p1.add(c_type);
        p1.add(l_item);
        p1.add(c_item);
        p1.add(l_bal);
        p1.add(t_bal);
        //p1.add(l_test);
        c.add(p1, BorderLayout.WEST);

        JPanel p2 = new JPanel();
        p2.setLayout(new GridLayout(5,1,10,10));
        p2.add(b_new);
        p2.add(b_update);
        p2.add(b_delete);
        p2.add(b_select);
        p2.add(b_clear);

        c.add(p2,BorderLayout.CENTER);
        //右边显示收支信息模块建立
        JPanel p3 = new JPanel();
        //let the table be 5 from the top and down and l and r
        p3.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createTitledBorder("显示收支信息"),
                BorderFactory.createEmptyBorder(5,5,5,5)));

        String[] column = { "编号", "日期", "类型","内容", "金额"};
        Object[][] row = new Object[50][5];

        //创建方法类
        method m=new method();
        //显示信息
        m.showDetail(row);
        table = new JTable(row, column);
        //滚动跳
        JScrollPane scrollPane = new JScrollPane(table);
        scrollPane.setViewportView(table);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        p3.add(scrollPane);
        c.add(p3,BorderLayout.EAST);
        b_update.addActionListener(this);
        b_delete.addActionListener(this);
        b_select.addActionListener(this);
        b_new.addActionListener(this);

        b_clear.addActionListener(this);

        //添加代码，为table添加鼠标点击事件监听addMouseListener
        table.addMouseListener(new MouseAdapter(){
            public void mouseClicked(MouseEvent e) {
//				仅当鼠标单击时响应
//				得到选中的行列的索引值
//              得到选中的单元格的值，表格中都是字符串
                int a= table.getSelectedRow();
                t_id.setText(row[a][0].toString());
                t_date.setText(row[a][1].toString());
                c_type.setSelectedItem(row[a][2].toString());
                c_item.setSelectedItem(row[a][3].toString());
                t_bal.setText(row[a][4].toString());
            }
        }
        );

        this.setResizable(false);
        this.setSize(800,300);
        Dimension screen = this.getToolkit().getScreenSize();
        this.setLocation((screen.width-this.getSize().width)/2,(screen.height-this.getSize().height)/2);
        this.setVisible(true);
    }

    //增删添改查
    public void actionPerformed(ActionEvent e) {
        if(b_select==e.getSource()){
            //查询所有收支信息 ok
            //添加代码
            this.dispatchEvent(new WindowEvent(this,WindowEvent.WINDOW_CLOSING) );
            try {
                new BalEditFrame();
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
        }else if(b_update==e.getSource()){
            // 修改某条收支信息
            //添加代码
            //添加方法类
            final int op=0;
            if(op==JOptionPane.showConfirmDialog(null,"确定修改？", "提示",JOptionPane.OK_CANCEL_OPTION))
            {
                method m=new method();
                ArrayList<MyAccount> a1=new ArrayList<>();
                a1=m.loadList(a1);
                int b=Integer.parseInt(t_id.getText());
                a1.remove(b-1);
                a1.add(b-1, new MyAccount(t_id.getText(),t_date.getText(), Objects.requireNonNull(c_type.getSelectedItem()).toString(), Objects.requireNonNull(c_item.getSelectedItem()).toString(),t_bal.getText()));
                this.dispatchEvent(new WindowEvent(this,WindowEvent.WINDOW_CLOSING) );
                m.delete();
                m.update(a1);
                a1=m.loadList(a1);
                try {
                    new BalEditInit(a1);
                } catch (IOException ioException) {
                    ioException.printStackTrace();
                }
            }
        }else if(b_delete==e.getSource()){   //删除某条收支信息
            final int op=0;
            if(op==JOptionPane.showConfirmDialog(null,"确定修改？", "提示",JOptionPane.OK_CANCEL_OPTION))
            {
                //写的方法类
                method m=new method();
                ArrayList<MyAccount> a1=new ArrayList<>();
                //方法读取文件对象，返回一个ArrayList<MyAccount>
                a1=m.loadList(a1);
                //读取编号项
                int b=Integer.parseInt(t_id.getText());
                //删除对应项
                a1.remove(b-1);
                //删除原界面
                this.dispatchEvent(new WindowEvent(this,WindowEvent.WINDOW_CLOSING) );
                //删除原文件，构建新文件
                m.delete();
                m.update(a1);
                //同步更新编辑界面
                a1=m.loadList(a1);
                try {
                    new BalEditInit(a1);
                } catch (IOException ioException) {
                    ioException.printStackTrace();
                }
                //添加代码
            }
        }else if(b_new==e.getSource()){   //新增某条收支信息
            //添加代码
            method m=new method();
            ArrayList<MyAccount> a1=new ArrayList<>();
            a1=m.loadList(a1);
             /*
                flag = 0为正常，1为编号重复，2为id编号不符合规则（为字符串）,3为日期不符合规范,4为输入金额负数
                日期输入个数 xxxx-xx-xx
            */
            int flag = 0;
            if(m.isNumeric(t_id.getText())){
                flag = 2;
            }else if (!m.isDate(t_date.getText())){
                    flag = 3;
            }else if(m.isNumeric(t_bal.getText())){
                flag = 4;
            } else{
                //遍历编号是否重复
                for (MyAccount myAccount : a1 ) {
                    if (t_id.getText().equals(myAccount.getId())) {
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag == 0) {
                a1.add(new MyAccount(t_id.getText(),t_date.getText(), Objects.requireNonNull(c_type.getSelectedItem()).toString(), Objects.requireNonNull(c_item.getSelectedItem()).toString(),t_bal.getText()));
            }else if(flag ==1){
                JOptionPane.showMessageDialog(null,"id重复，重新编辑", "警告", JOptionPane.ERROR_MESSAGE);
            }else if(flag == 2){
                JOptionPane.showMessageDialog(null,"id为非整数，重新编辑", "警告", JOptionPane.ERROR_MESSAGE);
            }else if(flag == 3){
                JOptionPane.showMessageDialog(null,"日期错误，重新编辑", "警告", JOptionPane.ERROR_MESSAGE);
            }else if(flag == 4){
                JOptionPane.showMessageDialog(null,"输入金额为负数，重新编辑", "警告", JOptionPane.ERROR_MESSAGE);
            }
            this.dispatchEvent(new WindowEvent(this,WindowEvent.WINDOW_CLOSING) );
            m.delete();
            m.update(a1);
            //同步更新编辑界面
            a1=m.loadList(a1);
            try {
                new BalEditInit(a1);
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
        }else if(b_clear==e.getSource()){   //清空输入框
            //添加代码	ok
            method m=new method();
            ArrayList<MyAccount> a1=new ArrayList<>();
            a1=m.loadList(a1);
            this.dispatchEvent(new WindowEvent(this,WindowEvent.WINDOW_CLOSING) );
            try {
                new BalEditInit(a1);
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
        }
    }

}

class BalEditInit extends BalEditFrame{
    BalEditInit(ArrayList<MyAccount> a1) throws IOException {
        super();
        Object[][] row = new Object[50][5];
        method m=new method();
        //显示信息
        m.showDetail(row,a1);
    }
}

class method{
    //对主界面构造函数数组进行赋值,从文件读取
    public void showDetail(Object[][] row) throws IOException {
        ArrayList<MyAccount> a1 = new ArrayList<>();
        ObjectInputStream ois = null;
        FileInputStream fis = null;
        try {
            //创建反序列化流
            fis = new FileInputStream("/home/david/Desktop/大二第二学期/JAVA/2021JAVA课程设计/xu.txt");
            ois = new ObjectInputStream(fis);
            a1 = (ArrayList<MyAccount>)(ois.readObject());
        } catch(Exception e){
            e.printStackTrace();
        } finally {
            assert ois != null;
            ois.close();
            fis.close();
        }
        showDetail(row, a1);

    }

    //对主界面构造函数数组赋值
    public void showDetail(Object[][] row, ArrayList<MyAccount> al) {
        for(int i=0;i<al.size();i++) {
            row[i][0]=al.get(i).getId();
            row[i][1]=al.get(i).getDate();
            row[i][2]=al.get(i).getType();
            row[i][3]=al.get(i).getContent();
            row[i][4]=al.get(i).getAmount();
        }
    }

    //加载目标文件信息，并以ArrayList<MyAccount>形式返回
    public ArrayList<MyAccount> loadList(ArrayList<MyAccount> a1) {
        try {
            FileInputStream fis= new FileInputStream("/home/david/Desktop/大二第二学期/JAVA/2021JAVA课程设计/xu.txt");
            ObjectInputStream ois=new ObjectInputStream(fis);
            a1=(ArrayList<MyAccount>)(ois.readObject());
            ois.close();
            fis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return a1;
    }

    //用于删除原文件
    public void delete() {
        boolean delFlag ;  //判断是否成功删除
        File f=new File("/home/david/Desktop/大二第二学期/JAVA/2021JAVA课程设计/xu.txt");
        delFlag = f.delete();
        if (!delFlag){
            System.out.println("删除文件失败");
        }
    }

    //创建新文件并写入信息
    public void update(ArrayList<MyAccount> a1){
        try {
            File f=new File("/home/david/Desktop/大二第二学期/JAVA/2021JAVA课程设计/xu.txt");
            FileOutputStream fos=new FileOutputStream(f);
            ObjectOutputStream oos=new ObjectOutputStream(fos);
            oos.writeObject(a1);
            oos.close();
            fos.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public  boolean isNumeric(String str){
        Pattern pattern = Pattern.compile("[0-9]*");
        return pattern.matcher(str).matches();
    }
    public  boolean isDate(String str){
        Pattern pattern = Pattern.compile("[0-9]{4}-[0-9]{2}-[0-9]{2}");
        return pattern.matcher(str).matches();
    }

}