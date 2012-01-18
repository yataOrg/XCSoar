/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000-2012 The XCSoar Project
  A detailed list of copyright holders can be found in the file "AUTHORS".

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#ifndef XCSOAR_UNITS_FORMATTER_HPP
#define XCSOAR_UNITS_FORMATTER_HPP

#include "Math/fixed.hpp"

#include <tchar.h>

class Angle;
struct GeoPoint;
class AtmosphericPressure;

/**
 * Namespace to manage unit display.
 */
namespace Units
{
  /**
   * Converts a double-based longitude into a formatted string
   * @param longitude The double-based longitude
   * @param buffer buffer string to write to (pointer)
   * @param size Size of the buffer
   */
  bool LongitudeToString(Angle longitude, TCHAR *buffer, size_t size);

  /**
   * Converts a double-based Latitude into a formatted string
   * @param Latitude The double-based Latitude
   * @param buffer buffer string to write to (pointer)
   * @param size Size of the buffer
   */
  bool LatitudeToString(Angle latitude, TCHAR *buffer, size_t size);

  /**
   * Convert a GeoPoint into a formatted string.
   */
  TCHAR *FormatGeoPoint(const GeoPoint &location, TCHAR *buffer, size_t size);

  /**
   * Converts a double-based Altitude into a formatted string
   * @param Altitude The double-based Altitude
   * @param buffer buffer string to write to (pointer)
   * @param size Size of the buffer
   */
  void FormatUserAltitude(fixed value, TCHAR *buffer, size_t size,
                          bool include_unit = true);

  /**
   * Converts a double-based Altitude into a formatted string of the alternate
   * altitude format
   * @param Altitude The double-based Altitude
   * @param buffer buffer string to write to (pointer)
   * @param size Size of the buffer
   */
  void FormatAlternateUserAltitude(fixed value, TCHAR *buffer, size_t size,
                                   bool include_unit = true);

  /**
   * Converts a double-based Arrival Altitude into a formatted string
   * @param Altitude The double-based Arrival Altitude
   * @param buffer buffer string to write to (pointer)
   * @param size Size of the buffer
   */
  void FormatUserArrival(fixed value, TCHAR *buffer, size_t size,
                         bool include_unit = true);

  /**
   * Converts a double-based horizontal Distance into a formatted string
   * @param Distance The double-based Distance
   * @param buffer buffer string to write to (pointer)
   * @param size Size of the buffer
   */
  void FormatUserDistance(fixed value, TCHAR *buffer, size_t size,
                          bool include_unit = true);

  void FormatUserMapScale(fixed value, TCHAR *buffer, size_t size,
                          bool include_unit = true);

  /**
   * Converts a double-based Speed into a formatted string
   * @param Speed The double-based Speed
   * @param buffer buffer string to write to (pointer)
   * @param size Size of the buffer
   * @return True if buffer long enough, False otherwise
   */
  void FormatUserSpeed(fixed value, TCHAR *buffer, size_t size,
                       bool include_unit = true, bool Precision = true);

  /**
   * Converts a double-based Speed into a formatted string
   * @param Speed The double-based Speed
   * @param buffer buffer string to write to (pointer)
   * @param size Size of the buffer
   * @return True if buffer long enough, False otherwise
   */
  void FormatUserWindSpeed(fixed value, TCHAR *buffer, size_t size,
                           bool include_unit = true, bool Precision = true);

  /**
   * Convert a speed [m/s] to the user's task speed and format it into
   * a string.
   *
   * @param value the speed value [m/s]
   */
  void FormatUserTaskSpeed(fixed value, TCHAR *buffer, size_t max_size,
                           bool include_unit=true, bool precision=true);

  /**
   * Converts a double-based vertical Speed into a formatted string
   * @param Speed The double-based vertical Speed
   * @param buffer buffer string to write to (pointer)
   * @param size Size of the buffer
   * @return True if buffer long enough, False otherwise
   */
  void FormatUserVSpeed(fixed value, TCHAR *buffer, size_t size,
                        bool include_unit = true);

  /**
   * Converts a temperature into a formatted string
   * @param temperature The double-based vertical Speed
   * @param buffer buffer string to write to (pointer)
   * @param size Size of the buffer
   */
  void FormatUserTemperature(fixed value, TCHAR *buffer, size_t size,
                             bool include_unit = true);

  /**
   * Converts a double-based Pressure into a formatted string
   * @param Pressure The double-based Pressure
   * @param buffer buffer string to write to (pointer)
   * @param size Size of the buffer
   * @return True if buffer long enough, False otherwise
   */
  bool FormatUserPressure(AtmosphericPressure value, TCHAR *buffer, size_t size,
                          bool include_unit = true);
  /**
   * Give the proper format to display the pressure
   * @param buffer buffer string to write to (pointer)
   * @param size Size of the buffer
   * @return True if buffer long enough, False otherwise
   */

  const TCHAR* GetFormatUserPressure();

  /**
   * Give the basic step for pressure editing
   * @return the step
   */

  fixed PressureStep();

  /**
   * precedes with "-" if time is negative
   * @param buffer returns HHMM
   * @param time input seconds
   */
  void TimeToTextHHMMSigned(TCHAR* buffer, int time);

  /**
   * sets HHMMSSSmart and SSSmart
   * if hours > 0, returns HHMM in buffer1 and SS in buffer2
   * if hours == 0, returns MMSS in buffer1 and "" in buffer2
   * @param d input seconds
   */
  void TimeToTextSmart(TCHAR *buffer1, TCHAR *buffer2, int time);
};

#endif
