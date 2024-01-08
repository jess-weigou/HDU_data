package com.example.fragementtest;

import com.google.okhttp.OkHttpConnection;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.ProtocolException;
import java.net.URL;
import java.util.Objects;

import okhttp3.OkHttp;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class HttpRequest {

    OkHttpClient client = new OkHttpClient();
    String getResponse(String path) throws IOException {
        Request request = new Request.Builder().url(path).addHeader("authorization","token 009205ef-9302-4ee7-87c8-b37789148a86")
                .build();

        Response response = client.newCall(request).execute();
        if (response.isSuccessful()) {
            return Objects.requireNonNull(response.body()).string();
        } else {
            throw new IOException("Unexpected code " + response);
        }
    }



}
