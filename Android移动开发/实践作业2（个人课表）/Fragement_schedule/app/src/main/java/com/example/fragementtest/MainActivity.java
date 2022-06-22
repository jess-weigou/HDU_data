package com.example.fragementtest;

import androidx.annotation.Nullable;
import androidx.fragment.app.FragmentActivity;
import androidx.fragment.app.FragmentTransaction;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.pm.ActivityInfo;
import android.content.res.Configuration;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

import com.example.fragementtest.model.Schedule;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


import com.example.fragementtest.model.ScheduleData;
import com.google.gson.Gson;

public class MainActivity extends FragmentActivity implements AdapterView.OnItemClickListener {
    static Map<String, ArrayList<ScheduleData>> map = new HashMap<String, ArrayList<ScheduleData>>();
//    ArrayList<ScheduleData> scheduleDatas_1 = null;
//    ArrayList<ScheduleData> scheduleDatas_2 = null;
//    ArrayList<ScheduleData> scheduleDatas_3 = null;
//    ArrayList<ScheduleData> scheduleDatas_4 = null;
//    ArrayList<ScheduleData> scheduleDatas_5 = null;
//    ArrayList<ScheduleData> scheduleDatas_6 = null;
//    ArrayList<ScheduleData> scheduleDatas_7 = null;
    MyAdapter adapter;
    ListView listView;
    String myID = "19141612";
    private final String[] strs = {"星期一", "星期二", "星期三", "星期四", "星期五", "星期六", "星期天"};

    public static int mPosition;
    MyFragment myFragment;

    protected void onCreate(@Nullable Bundle savedInstanceState) {
        ArrayList<ScheduleData> scheduleDatas = new ArrayList<ScheduleData>();
        //initMap();

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        scheduleDatas = initData(myID);
        initView(this);
//        // 把每一天的课表数据放到对应的arraylist里面
//        for (int i=0; i< scheduleDatas.size(); i++){
//            ScheduleData scheduleData = scheduleDatas.get(i);
//            map.get(scheduleData.WEEKDAY).add(scheduleData);
//        }

    }

//    public void initMap(){
//        scheduleDatas_1 = new ArrayList<ScheduleData>();
//        scheduleDatas_2 = new ArrayList<ScheduleData>();
//        scheduleDatas_3 = new ArrayList<ScheduleData>();
//        scheduleDatas_4 = new ArrayList<ScheduleData>();
//        scheduleDatas_5 = new ArrayList<ScheduleData>();
//        scheduleDatas_6 = new ArrayList<ScheduleData>();
//        scheduleDatas_7 = new ArrayList<ScheduleData>();
//        map.put("1",scheduleDatas_1);
//        map.put("2",scheduleDatas_2);
//        map.put("3",scheduleDatas_3);
//        map.put("4",scheduleDatas_4);
//        map.put("5",scheduleDatas_5);
//        map.put("6",scheduleDatas_6);
//        map.put("7",scheduleDatas_7);
//    }

    @SuppressLint("Range")
    public ArrayList<ScheduleData> initData(String staffID) {
        ArrayList<ScheduleData> scheduleDatas = new ArrayList<ScheduleData>();
        SQLiteOpenHelper helper = MySQLiteOpenHelper.getmInstance(this);
        SQLiteDatabase readableDatabase = helper.getReadableDatabase();
        String sql = "select * from person where staffID = ?";
        Cursor cursor = readableDatabase.rawQuery(sql, new String[]{staffID});
        if (!cursor.moveToNext()) {
            // 数据无课表数据,请求接口得到课表数据
            scheduleDatas = getScheduleData();
            SQLiteDatabase dbW = helper.getWritableDatabase();
            for (int i = 0; i < scheduleDatas.size(); i++) {
                ScheduleData scheduleData = scheduleDatas.get(i);
                if (i != scheduleDatas.size() - 1 && scheduleData.COURSECODE.equals(scheduleDatas.get(i + 1).COURSECODE)) {
                    scheduleDatas.get(i + 1).TEACHER += "," + scheduleData.TEACHER;
                    continue;
                }
                // 封装的数据插入
                scheduleData.insertSchedulestoDB(scheduleData, this);
            }
            dbW.execSQL("insert into person(staffID) values(?)", new Object[]{staffID});
            dbW.close();
        } else {
            // 数据库有数据,从数据库查询

            String sql2 = "select * from schedules where staffID = ?";
            ScheduleData scheduleData = new ScheduleData();
            cursor = readableDatabase.rawQuery(sql2, new String[]{staffID});
            scheduleDatas = scheduleData.getSchedulesFromDB(cursor);
            readableDatabase.close();
        }
        return scheduleDatas;
    }

    public ArrayList<ScheduleData> getScheduleData() {
        HttpRequest httpRequest = new HttpRequest();
        // Android 4.0 之后不能在主线程中请求HTTP请求
        final int[] flag = {0};
        final Schedule[] obj = {new Schedule()};

        new Thread(new Runnable() {

            @Override
            public void run() {
                try {
                    Gson gson = new Gson();
                    obj[0] = gson.fromJson(httpRequest.getResponse("https://api.hduhelp.com/base/student/schedule?schoolYear=2021-2022&semester=1"),
                            Schedule.class);

                    flag[0] = 1;
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

        }).start();
        // 轮询
        while (true) {
            if (flag[0] == 1) {
                break;
            }
        }
        return new ArrayList<ScheduleData>(Arrays.asList(obj[0].data));

    }


    public void initView(Context context) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                listView = findViewById(R.id.listview);
                adapter = new MyAdapter(strs, (MainActivity) context);
                listView.setAdapter(adapter);
                // 监听list点击事件
                listView.setOnItemClickListener((AdapterView.OnItemClickListener) context);
                myFragment = new MyFragment("1",myID);
                FragmentTransaction fragmentTransaction = getSupportFragmentManager()
                        .beginTransaction();
                fragmentTransaction.replace(R.id.fragment_container, myFragment);
                Bundle bundle = new Bundle();
                bundle.putString(MyFragment.TAG, strs[mPosition]);
                myFragment.setArguments(bundle);
                fragmentTransaction.commit();

            }
        }).start();

    }


    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        mPosition = position;
        // 及时刷新adapter
        adapter.notifyDataSetChanged();
        myFragment = new MyFragment( Integer.toString(position+1), myID);

            FragmentTransaction fragmentTransaction = getSupportFragmentManager()
                    .beginTransaction();
            fragmentTransaction.replace(R.id.fragment_container, myFragment);
            Bundle bundle = new Bundle();
            bundle.putString(MyFragment.TAG, strs[position]);
            myFragment.setArguments(bundle);
            fragmentTransaction.commit();

    }
    public void onConfigurationChanged(Configuration newConfig) {
// TODO Auto-generated method stub

        super.onConfigurationChanged(newConfig);

        if (newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE) {
            Toast.makeText(this, "landscape", Toast.LENGTH_SHORT).show();

        } else if (newConfig.orientation == Configuration.ORIENTATION_PORTRAIT) {
            Toast.makeText(this, "portrait", Toast.LENGTH_SHORT).show();

        }

    }
}