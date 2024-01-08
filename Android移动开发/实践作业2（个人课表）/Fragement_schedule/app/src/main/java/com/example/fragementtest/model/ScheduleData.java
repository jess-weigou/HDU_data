package com.example.fragementtest.model;

import android.annotation.SuppressLint;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import com.example.fragementtest.MySQLiteOpenHelper;

import java.io.Serializable;
import java.util.ArrayList;


public class ScheduleData  implements Serializable {
   Context context;

   public String CLASSROOM;
   public String COURSE;
   public String COURSECODE;
   public String DISTRIBUTE;
   public String ENDSECTION;
   public String ENDTIME;
   public String ENDWEEK;
   public String SCHOOLYEAR;
   public String SELECTCODE;
   public String SEMESTER;
   public String STAFFID;
   public String STARTSECTION;
   public String STARTTIME;
   public String STARTWEEK;
   public String TEACHER;
   public String WEEKDAY;


   public ScheduleData(){

   }

   @SuppressLint("Range")
   public ArrayList<ScheduleData> getSchedulesFromDB(Cursor cursor) {

      ArrayList<ScheduleData> scheduleDatas = new ArrayList<ScheduleData>();
      while (cursor.moveToNext()) {
         ScheduleData scheduleData = new ScheduleData();
         scheduleData.CLASSROOM = cursor.getString(cursor.getColumnIndex("classroom"));
         scheduleData.COURSE = cursor.getString(cursor.getColumnIndex("course"));
         scheduleData.COURSECODE = cursor.getString(cursor.getColumnIndex("coursecode"));
         scheduleData.DISTRIBUTE = cursor.getString(cursor.getColumnIndex("distribute"));
         scheduleData.ENDSECTION = cursor.getString(cursor.getColumnIndex("endsection"));
         scheduleData.ENDTIME = cursor.getString(cursor.getColumnIndex("endtime"));
         scheduleData.ENDWEEK = cursor.getString(cursor.getColumnIndex("endweek"));
         scheduleData.SCHOOLYEAR = cursor.getString(cursor.getColumnIndex("schoolyear"));
         scheduleData.SELECTCODE = cursor.getString(cursor.getColumnIndex("selectcode"));
         scheduleData.SEMESTER = cursor.getString(cursor.getColumnIndex("semester"));
         scheduleData.STAFFID = cursor.getString(cursor.getColumnIndex("staffid"));
         scheduleData.STARTSECTION = cursor.getString(cursor.getColumnIndex("startsection"));
         scheduleData.STARTTIME = cursor.getString(cursor.getColumnIndex("starttime"));
         scheduleData.STARTWEEK = cursor.getString(cursor.getColumnIndex("startweek"));
         scheduleData.TEACHER = cursor.getString(cursor.getColumnIndex("teacher"));
         scheduleData.WEEKDAY = cursor.getString(cursor.getColumnIndex("weekday"));
         scheduleDatas.add(scheduleData);
      }
      return scheduleDatas;
   }
   public void insertSchedulestoDB(ScheduleData scheduleData, Context context){
      SQLiteOpenHelper helper = MySQLiteOpenHelper.getmInstance(context);
      SQLiteDatabase dbW = helper.getWritableDatabase();
      dbW.execSQL("insert into schedules(" +
              "classroom   , " +
              "course      , " +
              "coursecode  , " +
              "distribute  , " +
              "endsection  , " +
              "endtime     , " +
              "endweek     , " +
              "schoolyear  , " +
              "selectcode  , " +
              "semester    , " +
              "staffid     , " +
              "startsection, " +
              "starttime   , " +
              "startweek   , " +
              "teacher     , " +
              "weekday     )  " +
              "values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)", new Object[]{
              scheduleData.CLASSROOM,
              scheduleData.COURSE,
              scheduleData.COURSECODE,
              scheduleData.DISTRIBUTE,
              scheduleData.ENDSECTION,
              scheduleData.ENDTIME,
              scheduleData.ENDWEEK,
              scheduleData.SCHOOLYEAR,
              scheduleData.SELECTCODE,
              scheduleData.SEMESTER,
              scheduleData.STAFFID,
              scheduleData.STARTSECTION,
              scheduleData.STARTTIME,
              scheduleData.STARTWEEK,
              scheduleData.TEACHER,
              scheduleData.WEEKDAY
      });
   }


}
