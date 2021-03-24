#pragma once
#include <QtWidgets>
class ViewerWidget :public QWidget {
	Q_OBJECT
private:
	QString name = "";
	QSize areaSize = QSize(0, 0);
	QImage* img = nullptr;
	QRgb* data = nullptr;
	QPainter* painter = nullptr;
	bool trebakreslit;

public:
	ViewerWidget(QString viewerName, QSize imgSize, QWidget* parent = Q_NULLPTR);
	~ViewerWidget();
	void resizeWidget(QSize size);

	//Image functions
	bool setImage(const QImage& inputImg);
	QImage* getImage() { return img; };
	bool isEmpty();
	void usecka_DDA(QPoint A, QPoint B, QColor color);
	void usecka_Bresenham(QPoint A, QPoint B, QColor color);
	void kruznica(QPoint A, QPoint B, QColor color);
	void kresliPolygon(QVector <QPoint> body, QColor color, int algo, QColor vypln, int algovypln);
	void kresliKrivku(QVector <QPoint> body, int algo, int algou);
	void kresliBod(QPoint A);
	void scanLine(QVector <QPoint> body, QColor color);
	void scanLineTri(QVector <QPoint> body, QColor color, int algovypln);
	QColor nearest(int x, int y, QVector<QPoint> body);
	QColor bary(int x, int y, QVector<QPoint> body);
	void orez(QVector<QPoint> body, int algo);

	//Data functions
	QRgb* getData() { return data; }
	void setPixel(int x, int y, const QColor& color);
	void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
	bool isInside(int x, int y) { return (x >= 0 && y >= 0 && x < img->width() && y < img->height()) ? true : false; }

	//Get/Set functions
	QString getName() { return name; }
	void setName(QString newName) { name = newName; }

	void setPainter() { painter = new QPainter(img); }
	void setDataPtr() { data = reinterpret_cast<QRgb*>(img->bits()); }

	int getImgWidth() { return img->width(); };
	int getImgHeight() { return img->height(); };

	void clear(QColor color = Qt::white);

public slots:
	void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;
};