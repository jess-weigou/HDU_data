package com.example.fragementtest;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.view.View;

import androidx.annotation.Nullable;

public class MySQLiteOpenHelper extends SQLiteOpenHelper {

    private static SQLiteOpenHelper mInstance;


    public static synchronized SQLiteOpenHelper getmInstance(Context context) {
        if (mInstance == null) {
            mInstance = new MySQLiteOpenHelper(context, "schedule.db", null, 1);
        }
        return mInstance;
    }

    private MySQLiteOpenHelper(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        String sql = "create table schedules(_id integer primary key autoincrement, " +
                "classroom      text," +
                "course         text ," +
                "coursecode     text," +
                "distribute     text," +
                "endsection     text," +
                "endtime        text," +
                "endweek        text," +
                "schoolyear     text," +
                "selectcode     text," +
                "semester       text," +
                "staffid        text," +
                "startsection   text," +
                "starttime      text," +
                "startweek      text," +
                "teacher        text," +
                "weekday        text)";
        String sql2 = "create table person(_id integer primary key autoincrement, staffID text, name text)";
        db.execSQL(sql);
        db.execSQL(sql2);
    }


    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }
}
