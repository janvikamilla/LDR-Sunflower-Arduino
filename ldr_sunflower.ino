#include <Servo.h>

Servo flower;

int ldrLeft = A0;
int ldrRight = A1;
int pos = 90;

void setup()
{
    flower.attach(9);
    flower.write(pos);
}

void loop()
{
    int leftValue = analogRead(ldrLeft);
    int rightValue = analogRead(ldrRight);

    if (leftValue > rightValue + 50)
    {
        pos--;
    }
    else if (rightValue > leftValue + 50)
    {
        pos++;
    }

    pos = constrain(pos, 0, 180);

    flower.write(pos);

    delay(15);
}
