package com.rangelovandkarev.virtualcontroller;

import android.graphics.LightingColorFilter;
import android.graphics.PorterDuff;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements SensorEventListener{

    Sensor accelerometer;
    SensorManager sm;
    TextView acceleration;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        sm=(SensorManager)getSystemService(SENSOR_SERVICE);
        accelerometer=sm.getDefaultSensor(Sensor.TYPE_GYROSCOPE);
        sm.registerListener(this, accelerometer, SensorManager.SENSOR_DELAY_NORMAL);

        acceleration = (TextView) findViewById(R.id.acceleration);
        Button button3 = (Button) findViewById(R.id.button3);
        button3.getBackground().setColorFilter(0xFFAA4400, PorterDuff.Mode.MULTIPLY);

    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        acceleration.setText("X: "+event.values[0]+ "\nY: "+
        event.values[1]+"\nZ: "+event.values[2]);
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {

    }
}
