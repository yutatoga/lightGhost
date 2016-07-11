#pragma once

#include "ofMain.h"
#include "ofxIntersection.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    // listener
    void frameRateChanged(int &frameRate);
		
    ofMesh mesh;
    ofMesh planecut;
    IsPlane plane;
    ofEasyCam camera;
    ofMaterial material;
    
    // gui
    bool showGuiAndDebug;
    ofxPanel panel;
    ofParameter<ofColor> planecutColor;
    ofParameter<ofColor> planeColor;
    ofParameter<ofColor> wireframeColor;
    ofParameter<ofColor> facesColor;
    ofParameter<bool> enableDrawWireFrame;
    ofParameter<bool> enableDrawFaces;
    ofParameter<bool> enableDrawPlane;
    ofParameter<bool> enableDrawPlanecut;
    ofParameter<float> wireframeLineWidth;
    ofParameter<float> planecutLineWidth;
    ofParameter<int> frameRate;
};
