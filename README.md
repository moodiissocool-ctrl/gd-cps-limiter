# CPS Limiter (Android / Geode)

This is a Geode source project for an Android Geometry Dash mod.

## What it does
- Adds a Target CPS setting from 10 to 17.
- Default is 10 CPS.
- Ignores presses that arrive sooner than the selected interval.
- It is a click-rate cap, not an autoclicker: it does not create extra clicks or force slower tapping to reach the selected CPS.

## Build
This folder is source code, not a ready-to-install `.geode` binary. Building requires the matching Geode SDK, Android NDK, and Geode CLI on a computer.

For a 64-bit Android build, install the Android 64-bit SDK binaries and build with the Geode CLI for `android64`. The resulting `.geode` file can then be installed through Geode on the phone.

Geode docs: https://docs.geode-sdk.org/
