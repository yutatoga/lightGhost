#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // mesh
    mesh.load("lofi-bunny.ply");
    
    // planecut
    planecut.setMode(OF_PRIMITIVE_LINES);
    
    // plane
    plane.set(ofPoint(0,0,0), ofVec3f(1,1,0));
    
    // listener
    frameRate.addListener(this, &ofApp::frameRateChanged);
    
    // gui
    showGuiAndDebug = true;
    panel.setup();
    panel.add(planecutColor.set("planecutColor", ofColor::red));
    panel.add(planeColor.set("planeColor", ofColor(0, 0, 255, 30)));
    panel.add(wireframeColor.set("wireframeColor", ofColor::gray));
    panel.add(facesColor.set("facesColor", ofColor(0, 0, 0, 180)));
    panel.add(enableDrawWireFrame.set("enableDrawWireFrame", true));
    panel.add(enableDrawFaces.set("enableDrawFaces", true));
    panel.add(enableDrawPlane.set("enableDrawPlane", true));
    panel.add(enableDrawPlanecut.set("enableDrawPlanecut", true));
    panel.add(wireframeLineWidth.set("wireframeLineWidth", 3, 1, 32));
    panel.add(planecutLineWidth.set("planecutLineWidth", 3, 1, 32));
    panel.add(frameRate.set("frameRate", 0, 0, 60));
    
    // debug
    ofSetVerticalSync(false);
    ofSetFrameRate(0);
}

void ofApp::frameRateChanged(int &frameRate){
    ofSetFrameRate(frameRate);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    camera.begin();
    material.begin();
    
    // wireframe
    if(enableDrawWireFrame) {
        ofSetColor(wireframeColor);
        ofSetLineWidth(wireframeLineWidth);
        mesh.drawWireframe();
        ofSetLineWidth(1);
        ofSetColor(255);
    }
    
    // planecut
    // - update planecut
    planecut.clear();
    // - check intersection
    ofxIntersection intersection;
    IsTriangle triangle;
    for(int i=0; i < mesh.getUniqueFaces().size(); i++){
        triangle.set(mesh.getUniqueFaces().at(i));
        const IntersectionData &intersectionData = intersection.PlaneTriangleIntersection(plane, triangle);
        if(intersectionData.isIntersection){
            planecut.addVertex(intersectionData.pos);
            planecut.addVertex(intersectionData.pos+intersectionData.dir);
        }
    }
    // - draw planecut
    if (enableDrawPlanecut) {
        ofSetColor(planecutColor);
        ofSetLineWidth(planecutLineWidth);
        planecut.draw();
        ofSetLineWidth(1);
        ofSetColor(255);
    }
    
    // mesh (faces)
    if(enableDrawFaces) {
        ofSetColor(facesColor);
        mesh.draw();
        ofSetColor(255);
    }
    
    // plane
    // - rotate plane
    ofVec3f normal = plane.getNormal();
    normal.rotate(1, ofVec3f(0,1,0));
    plane.setNormal(normal);
    // - draw plane
    if(enableDrawPlane) {
        ofSetColor(planeColor);
        plane.draw();
        ofSetColor(255);
    }
    
    material.end();
    camera.end();
    ofDisableDepthTest();
    
    // gui and debug
    if (showGuiAndDebug) {
        // gui
        panel.draw();
        
        // debug
        stringstream ss;
        ss << "framerate: " << ofToString(ofGetFrameRate(), 0);
        ofDrawBitmapString(ss.str(), 14, 24);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 'h':
            showGuiAndDebug = !showGuiAndDebug;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
