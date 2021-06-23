package   文件和流;
import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

class _5 {
    public static void main(String[] args) {
        new FileFrame();
    }
}

class FileFrame extends Frame implements ActionListener {
    TextArea text;
    Button open, quit;
    FileDialog fileDialog;

    FileFrame() {
        super("获取并显示文本文件");
        text = new TextArea(28, 80);
        open = new Button("打开");
        quit = new Button("关闭");
        open.addActionListener(this);
        quit.addActionListener(this);
        setLayout(new FlowLayout());
        add(text);
        add(open);
        add(quit);
        setSize(700, 560);
        show();
    }


    public void actionPerformed(ActionEvent e) {
        if (e.getActionCommand() == "打开") {
            fileDialog = new FileDialog(this, "打开文件", FileDialog.LOAD);
            fileDialog.setDirectory("/home/david/Desktop/JAVA");//设置文件对话框的基础目录
            fileDialog.show(); //弹出并显示文件对话框，程序暂停直至用户选定一文件
            //TODO
            String fileName = fileDialog.getDirectory() + fileDialog.getFile();
            try {
                BufferedReader bf = new BufferedReader(new FileReader(fileName));
                while (bf.ready()) {
                    this.text.append(bf.readLine()+"\n");
                }
            } catch (FileNotFoundException fileNotFoundException) {
                System.out.println(fileNotFoundException.getMessage());
            } catch (IOException ioException) {
                System.out.println(ioException.getMessage());
            }
        }
        if (e.getActionCommand() == "关闭") {
            dispose();
            System.exit(0);
        }
    }
}