package com.example.fragementtest;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import androidx.appcompat.app.AlertDialog;

import com.example.fragementtest.model.ScheduleData;

import java.util.ArrayList;

public class MainActivity3 extends AppCompatActivity {
    EditText editText1 = null;
    EditText editText2 = null;
    EditText editText3 = null;
    EditText editText4 = null;
    EditText editText5 = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        editText1 = findViewById(R.id.edit1);
        editText2 = findViewById(R.id.edit2);
        editText3 = findViewById(R.id.edit3);
        editText4 = findViewById(R.id.edit4);
        editText5 = findViewById(R.id.edit5);
        SharedPreferences sharedPreferences = getSharedPreferences("schedule", Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sharedPreferences.edit();//获取编辑器
        editText1.setText(sharedPreferences.getString("course", "none"));
        editText2.setText(sharedPreferences.getString("teacher", "none"));
        editText3.setText(sharedPreferences.getString("classroom", "none"));
        editText4.setText(sharedPreferences.getString("startSection", "none"));
        editText5.setText(sharedPreferences.getString("endSection", "none"));
        SQLiteOpenHelper helper = MySQLiteOpenHelper.getmInstance(this);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);
        Intent intent = getIntent();
        Button button1 = findViewById(R.id.but1_add);
        int[] busyFlag = new int[13];

        // get the data
        Bundle bundle =  intent.getExtras();
        ArrayList<ScheduleData> scheduleData = (ArrayList<ScheduleData>) bundle.get("schedule");
        for (int i=0;i< scheduleData.size();i++){
            int start = Integer.parseInt(scheduleData.get(i).STARTSECTION);
            int end = Integer.parseInt(scheduleData.get(i).ENDSECTION);
            for (int j= start; j<= end; j++){
                busyFlag[j] = 1;
            }
        }

        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                ScheduleData scheduleData1 = new ScheduleData();
                scheduleData1.COURSE = editText1.getText().toString();
                scheduleData1.TEACHER = editText2.getText().toString();
                scheduleData1.CLASSROOM = editText3.getText().toString();
                scheduleData1.STARTSECTION = editText4.getText().toString();
                scheduleData1.ENDSECTION = editText5.getText().toString();
                scheduleData1.STAFFID = scheduleData.get(0).STAFFID;
                scheduleData1.WEEKDAY = scheduleData.get(0).WEEKDAY;
                if (editText1.getText().toString().equals("") || editText2.getText().toString().equals("") || editText3.getText().toString().equals("") || editText4.getText().toString().equals("") || editText5.getText().toString().equals("")){
                    new AlertDialog.Builder(
                            MainActivity3.this)
                            .setTitle("提示")
                            .setMessage("不能有空")
                            .setPositiveButton("确定", null)
                            .show();

                }
                if (busyFlag[Integer.parseInt(scheduleData1.STARTSECTION)] ==0 && busyFlag[Integer.parseInt(scheduleData1.ENDSECTION)] == 0){
                    // 可以插入
                    scheduleData1.insertSchedulestoDB(scheduleData1, MainActivity3.this);
                    new AlertDialog.Builder(
                            MainActivity3.this)
                            .setTitle("提示")
                            .setMessage("插入成功")
                            .setPositiveButton("确定", null)
                            .show();

                }else{
                    // 不能插入
                    new AlertDialog.Builder(
                            MainActivity3.this)
                            .setTitle("提示")
                            .setMessage("所添加的课与原有课冲突，请重新排课")
                            .setPositiveButton("确定", null)
                            .show();

                }
            }
        });
    }

    @Override
    protected void onPause() {
        super.onPause();
        SharedPreferences sharedPreferences = getSharedPreferences("schedule", Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sharedPreferences.edit();//获取编辑器
        editor.putString("course", editText1.getText().toString());
        editor.putString("teacher", editText2.getText().toString());
        editor.putString("classroom", editText3.getText().toString());
        editor.putString("startSection", editText4.getText().toString());
        editor.putString("endSection", editText5.getText().toString());
        editor.commit();//提交修改
    }
}