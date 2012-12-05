/*
 * Copyright 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include "WallInspectorDialog.hh"

using namespace gazebo;
using namespace gui;

/////////////////////////////////////////////////
WallInspectorDialog::WallInspectorDialog(QWidget *_parent)
  : QDialog(_parent)
{
  this->setObjectName("wallInspectorDialog");

  this->setWindowTitle(tr("Wall Inspector"));

  QLabel *wallLabel = new QLabel(tr("Wall Name: "));
  this->wallNameLabel = new QLabel(tr(""));

  QHBoxLayout *nameLayout = new QHBoxLayout;
  nameLayout->addWidget(wallLabel);
  nameLayout->addWidget(wallNameLabel);

  QLabel *lengthLabel = new QLabel(tr("Length: "));
  this->lengthSpinBox = new QDoubleSpinBox;
  this->lengthSpinBox->setRange(-1000, 1000);
  this->lengthSpinBox->setSingleStep(0.001);
  this->lengthSpinBox->setDecimals(3);
  this->lengthSpinBox->setValue(0.000);

  QHBoxLayout *lengthLayout = new QHBoxLayout;
  lengthLayout->addWidget(lengthLabel);
  lengthLayout->addWidget(lengthSpinBox);

  QLabel *lengthCaptionLabel = new QLabel(
    tr("(Distance from Start to End point)\n"));

  QLabel *startLabel = new QLabel(tr("Start Point"));
  QLabel *endLabel = new QLabel(tr("End Point"));
  QHBoxLayout *startEndLayout = new QHBoxLayout;
  startEndLayout->addWidget(startLabel);
  startEndLayout->addWidget(endLabel);

  QLabel *startXLabel = new QLabel(tr("x: "));
  QLabel *startYLabel = new QLabel(tr("y: "));

  this->startXSpinBox = new QDoubleSpinBox;
  this->startXSpinBox->setRange(-1000, 1000);
  this->startXSpinBox->setSingleStep(0.001);
  this->startXSpinBox->setDecimals(3);
  this->startXSpinBox->setValue(0.000);

  this->startYSpinBox = new QDoubleSpinBox;
  this->startYSpinBox->setRange(-1000, 1000);
  this->startYSpinBox->setSingleStep(0.001);
  this->startYSpinBox->setDecimals(3);
  this->startYSpinBox->setValue(0.000);

  QLabel *endXLabel = new QLabel(tr("x: "));
  QLabel *endYLabel = new QLabel(tr("y: "));

  this->endXSpinBox = new QDoubleSpinBox;
  this->endXSpinBox->setRange(-1000, 1000);
  this->endXSpinBox->setSingleStep(0.001);
  this->endXSpinBox->setDecimals(3);
  this->endXSpinBox->setValue(0.000);

  this->endYSpinBox = new QDoubleSpinBox;
  this->endYSpinBox->setRange(-1000, 1000);
  this->endYSpinBox->setSingleStep(0.001);
  this->endYSpinBox->setDecimals(3);
  this->endYSpinBox->setValue(0.000);

  QGridLayout *startXYLayout = new QGridLayout;
  startXYLayout->addWidget(startXLabel, 0, 0);
  startXYLayout->addWidget(startXSpinBox, 0, 1);
  startXYLayout->addWidget(startYLabel, 1, 0);
  startXYLayout->addWidget(startYSpinBox, 1, 1);
  startXYLayout->setColumnStretch(1, 1);
  startXYLayout->setAlignment(startXSpinBox, Qt::AlignLeft);
  startXYLayout->setAlignment(startYSpinBox, Qt::AlignLeft);

  QGridLayout *endXYLayout = new QGridLayout;
  endXYLayout->addWidget(endXLabel, 0, 0);
  endXYLayout->addWidget(endXSpinBox, 0, 1);
  endXYLayout->addWidget(endYLabel, 1, 0);
  endXYLayout->addWidget(endYSpinBox, 1, 1);
  endXYLayout->setColumnStretch(1, 1);
  endXYLayout->setAlignment(endXSpinBox, Qt::AlignLeft);
  endXYLayout->setAlignment(endYSpinBox, Qt::AlignLeft);

  QHBoxLayout *xyLayout = new QHBoxLayout;
  xyLayout->addLayout(startXYLayout);
  xyLayout->addLayout(endXYLayout);

  QVBoxLayout * lengthGroupLayout = new QVBoxLayout;
  lengthGroupLayout->addLayout(lengthLayout);
  lengthGroupLayout->addWidget(lengthCaptionLabel);
  lengthGroupLayout->addLayout(startEndLayout);
  lengthGroupLayout->addLayout(xyLayout);

  QGroupBox *lengthGroupBox = new QGroupBox(tr("Length"));
  lengthGroupBox->setLayout(lengthGroupLayout);

  QLabel *heightLabel = new QLabel(tr("Height: "));
  this->heightSpinBox = new QDoubleSpinBox;
  this->heightSpinBox->setRange(-1000, 1000);
  this->heightSpinBox->setSingleStep(0.001);
  this->heightSpinBox->setDecimals(3);
  this->heightSpinBox->setValue(0.000);

  QLabel *thicknessLabel = new QLabel(tr("Thickness "));
  this->thicknessSpinBox = new QDoubleSpinBox;
  this->thicknessSpinBox->setRange(-1000, 1000);
  this->thicknessSpinBox->setSingleStep(0.001);
  this->thicknessSpinBox->setDecimals(3);
  this->thicknessSpinBox->setValue(0.000);

  QGridLayout *heightThicknessLayout = new QGridLayout;
  heightThicknessLayout->addWidget(heightLabel, 0, 0);
  heightThicknessLayout->addWidget(heightSpinBox, 0, 1);
  heightThicknessLayout->addWidget(thicknessLabel, 1, 0);
  heightThicknessLayout->addWidget(thicknessSpinBox, 1, 1);

  QLabel *materialLabel = new QLabel(tr("Material: "));
  this->materialComboBox = new QComboBox;
  materialComboBox->addItem(QString("Concrete"));

  QHBoxLayout *materialLayout = new QHBoxLayout;
  materialLayout->addWidget(materialLabel);
  materialLayout->addWidget(materialComboBox);

  QHBoxLayout *buttonsLayout = new QHBoxLayout;
  QPushButton *cancelButton = new QPushButton(tr("&Cancel"));
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(OnCancel()));
  QPushButton *OKButton = new QPushButton(tr("&OK"));
  connect(OKButton, SIGNAL(clicked()), this, SLOT(OnOK()));
  buttonsLayout->addWidget(cancelButton);
  buttonsLayout->addWidget(OKButton);
  buttonsLayout->setAlignment(Qt::AlignRight);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addLayout(nameLayout);
  mainLayout->addWidget(lengthGroupBox);
  mainLayout->addLayout(heightThicknessLayout);
  mainLayout->addLayout(materialLayout);
  mainLayout->addLayout(buttonsLayout);

  this->setLayout(mainLayout);
}

/////////////////////////////////////////////////
WallInspectorDialog::~WallInspectorDialog()
{
}

/////////////////////////////////////////////////
double WallInspectorDialog::GetLength()
{
  return this->lengthSpinBox->value();
}

/////////////////////////////////////////////////
math::Vector2d WallInspectorDialog::GetStartPosition()
{
  return math::Vector2d(this->startXSpinBox->value(),
      this->startYSpinBox->value());
}

/////////////////////////////////////////////////
math::Vector2d WallInspectorDialog::GetEndPosition()
{
  return math::Vector2d(this->endXSpinBox->value(),
      this->endYSpinBox->value());
}

/////////////////////////////////////////////////
std::string WallInspectorDialog::GetMaterial()
{
  return this->materialComboBox->currentText().toStdString();
}

/////////////////////////////////////////////////
void WallInspectorDialog::OnCancel()
{
  this->close();
}

/////////////////////////////////////////////////
void WallInspectorDialog::OnOK()
{
  /// TODO:
  this->accept();
}
