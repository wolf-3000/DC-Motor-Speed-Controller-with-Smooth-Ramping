# Arduino Nano DC Motor Speed Controller with Smooth Ramping

## Overview

This project implements a DC motor speed controller on an Arduino Nano using a potentiometer and an L298N motor driver. The system reads the potentiometer position, applies a moving average filter to smooth noisy readings, and gradually adjusts the motor speed using a circular buffer.

## Features

* DC motor speed control using a potentiometer
* PWM-based motor speed regulation
* Moving average filtering
* Smooth acceleration and deceleration (ramping)
* Serial Monitor status dashboard
* Non-blocking timing using `millis()`
* Modular function-based software design

## Hardware Used

* Arduino Nano
* L298N Motor Driver
* DC Motor
* Potentiometer
* Breadboard
* Jumper Wires
* USB Cable

## System Behavior

### Speed Control

The potentiometer controls the target motor speed.

### Moving Average Filtering

Multiple potentiometer readings are averaged to reduce noise and improve stability.

### Smooth Ramping

The motor speed does not instantly jump to the target value.

If the target speed increases:

* Motor gradually accelerates

If the target speed decreases:

* Motor gradually decelerates

### Serial Dashboard

The system continuously reports:

* Target speed
* Current speed
* Motor status

Possible statuses:

* Ramping
* Braking
* Steady

## How It Works

The Arduino continuously reads the potentiometer value.

A moving average filter smooths the input signal.

The filtered value is mapped to a PWM range of 0–255.

A ramping algorithm gradually changes the current motor speed toward the target speed.

The motor driver receives the updated PWM signal and adjusts the motor speed.

System status information is printed to the Serial Monitor every 500 milliseconds.

## Project Structure
<img width="1496" height="1496" alt="picture" src="https://github.com/user-attachments/assets/5644c8b3-8a9a-40f5-aaf7-221968a349eb" />


## Concepts Learned

* PWM Motor Control
* Analog-to-Digital Conversion (ADC)
* Moving Average Filtering
* Signal Conditioning
* Non-Blocking Timing using `millis()`
* Software Ramping Algorithms
* Modular Embedded Software Design
* Serial Debugging

## Example Output

```text
Target: 180 | Current: 165 | Ramping...

Target: 180 | Current: 180 | Steady

Target: 100 | Current: 140 | Braking

Target: 100 | Current: 100 | Steady
```

## Testing

The system was tested by:

* Rotating the potentiometer through its full range
* Verifying smooth motor acceleration
* Verifying smooth motor deceleration
* Monitoring PWM response through motor behavior
* Checking moving average filtering stability
* Monitoring system status through the Serial Monitor

## Future Improvements

* Add motor direction control
* Add start/stop push-button functionality
* Add encoder feedback for closed-loop control
* Add fault detection and protection logic
* Add LCD or OLED display
* Implement a finite state machine for operating modes

## Lessons Learned

Moving average filtering can significantly reduce noisy analog sensor readings.

Circular buffer improves motor control by preventing abrupt speed changes.

Non-blocking timing with `millis()` allows responsive embedded applications.

Separating functionality into dedicated functions improves readability and maintainability.

Serial debugging is useful for monitoring system behavior and verifying control logic.

## Demo
Demo video is included in the repository

Photos and videos of the breadboard setup, motor speed control, ramping behavior, and Serial Monitor output are included in this repository.
