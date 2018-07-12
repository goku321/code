function constructSegmentTree(arr, n) {
  // Calculate height of the tree.
  const height = parseInt(Math.ceil(Math.log2(n)));

  // Maximum size of the segment tree.
  const maxSize = parseInt(2 * Math.pow(2, height) - 1);
  console.log(maxSize);

  // Allocate Memory for the Segment tree.
  const segmentTree = new Array(maxSize);
  console.log(segmentTree);

  buildST(arr, 0, n-1, segmentTree, 0);
  console.log(segmentTree);
  return segmentTree;
}

function buildST(arr, startIndex, endIndex, segmentTree, currentIndex) {
  if (startIndex === endIndex) {
    segmentTree[currentIndex] = arr[startIndex];
    return arr[startIndex];
  }

  const mid = parseInt((startIndex + endIndex) / 2);
  segmentTree[currentIndex] = buildST(arr, startIndex, mid, segmentTree, 2*currentIndex + 1) +
                              buildST(arr, mid+1, endIndex, segmentTree, 2*currentIndex + 2);
  return segmentTree[currentIndex];
}

function updateValue(arr, segmentTree, n, i, value) {
  if (i < 0 || i > n-1) {
    console.log('Invalid update operation');
    return;
  }

  // Get the difference b/w the new value and the old value
  const diff = value - arr[i];
  arr[i] = value;

  updateValueUtil(segmentTree, 0, n-1, i, diff, 0);
}

function updateValueUtil(segmentTree, ss, se, i, diff, rootIndex) {
  console.log(ss, se);
  if (i < ss || i > se) return;

  segmentTree[rootIndex] = segmentTree[rootIndex] + diff;

  if (ss != se) {
    let mid = parseInt((ss + se) / 2);
    updateValueUtil(segmentTree, ss, mid, i, diff, 2*rootIndex + 1);
    updateValueUtil(segmentTree, mid+1, se, i, diff, 2*rootIndex + 2);
  }
}

// Main

const arr = [1, 3, 4, 5];

segmentTree = constructSegmentTree(arr, 4);
updateValue(arr, segmentTree, 4, 3, -1);
console.log(arr, segmentTree);