package com.example.fragementtest;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;


import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import com.example.fragementtest.model.ScheduleData;

import java.util.ArrayList;


public class MainActivity2 extends AppCompatActivity {
    EditText editText1 = null;
    EditText editText2 = null;
    EditText editText3 = null;
    Button button1 = null;
    Button button2 = null;
    Button button3 = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        SQLiteOpenHelper helper = MySQLiteOpenHelper.getmInstance(this);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        editText1 = findViewById(R.id.etName);
        editText2 = findViewById(R.id.etAddress);
        editText3 = findViewById(R.id.etClassName);
        button1 = findViewById(R.id.btShared);
        button2 = findViewById(R.id.btSaveDB);
        button3 = findViewById(R.id.btDelDB);
        Intent intent = getIntent();
        // get the data
        Bundle bundle =  intent.getExtras();
        ArrayList<ScheduleData> scheduleData = (ArrayList<ScheduleData>) bundle.get("schedule");
        MyAdapter2 _MyAdapter=new MyAdapter2(this, scheduleData);
        // consfer to list
        Spinner spinner  = (Spinner) findViewById(R.id.spinner);
        spinner.setAdapter(_MyAdapter);
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String select_item = parent.getItemAtPosition(position).toString();
                System.out.println(select_item);
                editText3.setText(scheduleData.get(position).COURSE);
                editText1.setText(scheduleData.get(position).TEACHER);
                editText2.setText(scheduleData.get(position).CLASSROOM);
                button1.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        SharedPreferences sharedPreferences = getSharedPreferences("schedule", Context.MODE_PRIVATE);
                        SharedPreferences.Editor editor = sharedPreferences.edit();//获取编辑器
                        editor.putString("TeacherName", editText1.getText().toString());
                        editor.putString("classroom", editText2.getText().toString());
                        editor.commit();//提交修改
                    }
                });
                button2.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        if( scheduleData.size() != 0){
                            String sql = "update schedules set classroom = ?, teacher = ? where staffid = ? and course = ?";
                            SQLiteDatabase dbW = helper.getWritableDatabase();
                            dbW.execSQL(sql, new String[]{editText2.getText().toString(),editText1.getText().toString(), scheduleData.get(0).STAFFID, editText3.getText().toString()});
                            new AlertDialog.Builder(
                                    MainActivity2.this)
                                    .setTitle("提示")
                                    .setMessage("修改成功")
                                    .setPositiveButton("确定", null)
                                    .show();
                        }else{
                            System.out.println("无课");
                        }

                    }
                });
                button3.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        String sql = "delete from schedules where course = ?";
                        SQLiteDatabase dbW = helper.getWritableDatabase();
                        dbW.execSQL(sql, new String[]{scheduleData.get(position).COURSE});
                        new AlertDialog.Builder(
                                MainActivity2.this)
                                .setTitle("提示")
                                .setMessage("删除成功")
                                .setPositiveButton("确定", null)
                                .show();
                    }
                });
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });
    }


}