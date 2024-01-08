package com.example.fragementtest;

import android.annotation.SuppressLint;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import com.example.fragementtest.model.ScheduleData;

import java.util.ArrayList;

public class MyAdapter2 extends BaseAdapter {
    private ArrayList<ScheduleData> mList;
    private Context mContext;

    public MyAdapter2(Context pContext, ArrayList<ScheduleData> pList) {
        this.mContext = pContext;
        this.mList = pList;
    }

    @Override
    public int getCount() {
        return mList.size();
    }

    @Override
    public Object getItem(int position) {
        return mList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        LayoutInflater _LayoutInflater=LayoutInflater.from(mContext);
        convertView=_LayoutInflater.inflate(R.layout.item_custom, null);
        if(convertView!=null) {
            TextView _TextView1=(TextView)convertView.findViewById(R.id.TextView1);
            _TextView1.setText(mList.get(position).COURSE);
        }
        return convertView;
    }
}
