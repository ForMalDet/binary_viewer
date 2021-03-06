/*
 * MIT License
 * 
 * Copyright (c) 2015, 2017 Kent A. Vander Velden
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <qapplication.h>

#include "main_app.h"
#include "version.h"

extern const QString base_caption = appname + " " + appversion + " " __DATE__ + " " + __TIME__;
QString caption = base_caption;

//----------------------------------------------------------------------

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  MainApp a;

  if(argc != 2) {
    fprintf(stderr, "usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if(!a.load_file(argv[1])) {
    exit(EXIT_FAILURE);
  }

  a.showFullScreen();
  a.setWindowTitle(base_caption);

  return a.exec();
}
