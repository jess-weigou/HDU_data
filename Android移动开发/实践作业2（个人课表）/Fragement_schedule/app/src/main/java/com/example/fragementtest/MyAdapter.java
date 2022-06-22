package com.example.fragementtest;

import android.content.Context;
import android.graphics.Color;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.TextView;

import java.util.List;

public class MyAdapter extends BaseAdapter {
    String[] data;
    Context context;
    public static int mPosition;
    public MyAdapter(String[]  data, MainActivity context) {
        this.data = data;
        this.context = context;
    }

    @Override
    public int getCount() {
        return data.length;
    }

    @Override
    public Object getItem(int position) {
        return data[position];
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder viewHolder;
        if(convertView == null) {
            mPosition = position;
            viewHolder = new ViewHolder();
            convertView = LayoutInflater.from(context).inflate(R.layout.list_text, parent, false);
            viewHolder.textView = convertView.findViewById(R.id.list_text);
            viewHolder.textView.setText(data[position]);

            if (position == MainActivity.mPosition) {
                convertView.setBackgroundResource(R.drawable.tongcheng_all_bg01);
            } else {
                convertView.setBackgroundColor(Color.parseColor("#f4f4f4"));
            }

            convertView.setTag(viewHolder);

        }else{
            viewHolder = (ViewHolder) convertView.getTag();
        }

        viewHolder.textView.setText(data[position]);
        if (position == MainActivity.mPosition) {
            convertView.setBackgroundResource(R.drawable.tongcheng_all_bg01);
        } else {
            convertView.setBackgroundColor(Color.parseColor("#f4f4f4"));
        }
//        Log.e("leo","getView: "+ position);
        return convertView;
    }

    private static final class ViewHolder{
        TextView textView;

    }
}
