#include "bitmap_image.hpp"
#include <iostream>
#include <string>

// Calculate average pixel intensity to use as threshold
unsigned char calculateThreshold(bitmap_image &image) {
    unsigned long long totalIntensity = 0;
    const unsigned int width = image.width();
    const unsigned int height = image.height();

    // Sum up all pixel intensities
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            rgb_t pixel;
            image.get_pixel(x, y, pixel);
            totalIntensity += pixel.red;
        }
    }

    // Return average intensity
    return static_cast<unsigned char>(totalIntensity / (width * height));
}

// Convert grayscale image to binary (black and white only)
void binarizeImage(bitmap_image &image, unsigned char threshold) {
    const unsigned int width = image.width();
    const unsigned int height = image.height();

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            rgb_t pixel;
            image.get_pixel(x, y, pixel);

            // Set pixel to black or white based on threshold
            if (pixel.red < threshold) {
                image.set_pixel(x, y, 0, 0, 0);
            } else {
                image.set_pixel(x, y, 255, 255, 255);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) return 1;

    const std::string inputImageFile = argv[1];
    const std::string outputImageFile = argv[2];

    // Load input image
    bitmap_image image(inputImageFile);
    if (!image) return 1;

    // Convert to grayscale
    image.convert_to_grayscale();
    
    // Calculate threshold and apply binarization
    unsigned char threshold = calculateThreshold(image);
    binarizeImage(image, threshold);
    
    // Save result
    image.save_image(outputImageFile);

    return 0;
}
