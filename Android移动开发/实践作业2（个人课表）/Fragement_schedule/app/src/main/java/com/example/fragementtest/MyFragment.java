package com.example.fragementtest;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;

import com.example.fragementtest.model.ScheduleData;

import java.util.ArrayList;


public class MyFragment extends Fragment {

    public static final String TAG = "MyFragment";
    private String seq;
    private  String staffID;
    private ArrayList<ScheduleData> scheduleDatas;

    public MyFragment(ArrayList<ScheduleData> scheduleDatas) {
        //得到数据
        this.scheduleDatas = scheduleDatas;
    }
    public MyFragment(String seq, String staffID) {
        //得到数据
        this.seq = seq;
        this.staffID = staffID;
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_my, null);
        TextView tv_title = (TextView) view.findViewById(R.id.tv_title);
        LinearLayout linearLayout = view.findViewById(R.id.fragment);
        Button button = view.findViewById(R.id.btn1);
        Button button2 = view.findViewById(R.id.btn2);
        SQLiteOpenHelper helper = MySQLiteOpenHelper.getmInstance(getContext());
        SQLiteDatabase readableDatabase = helper.getReadableDatabase();
        // 修改课表按钮
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getActivity(), MainActivity2.class);
                intent.putExtra("schedule", scheduleDatas);
                startActivity(intent);
            }
        });
        // 添加课表按钮
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getActivity(), MainActivity3.class);
                intent.putExtra("schedule", scheduleDatas);
                startActivity(intent);
            }
        });
        String text = "";
        // 如果没数据
        ScheduleData scheduleData = new ScheduleData();
        String sql = "select * from schedules where WEEKDAY = ? and STAFFID = ?";
        Cursor cursor = readableDatabase.rawQuery(sql, new String[]{seq, staffID});
        scheduleDatas = scheduleData.getSchedulesFromDB(cursor);
        if (scheduleDatas.size() == 0) {
        } else {
            for(int i=0; i<scheduleDatas.size();i++){
                 text = text +  scheduleDatas.get(i).COURSE+"  "+scheduleDatas.get(i).TEACHER+"\n"
                         +"第"+scheduleDatas.get(i).STARTSECTION+"-"+scheduleDatas.get(i).ENDSECTION+"节   "+scheduleDatas.get(i).CLASSROOM;
                 if(i != scheduleDatas.size()-1){
                     text = text + "\n----------------------------------------------------\n";
                 }

            }
            tv_title.setText(text);
        }
        return view;
    }


}

