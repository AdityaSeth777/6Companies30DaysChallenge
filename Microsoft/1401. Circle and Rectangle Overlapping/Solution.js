var checkOverlap = function(radius, xCenter, yCenter, x1, y1, x2, y2) {
    const xEdge = Math.max(x1, Math.min(x2, xCenter));
    const yEdge = Math.max(y1, Math.min(y2, yCenter));
    const xDistance = xCenter - xEdge;
    const yDistance = yCenter - yEdge;
    //Aditya Seth.
    return xDistance ** 2 + yDistance ** 2 <= radius ** 2
};