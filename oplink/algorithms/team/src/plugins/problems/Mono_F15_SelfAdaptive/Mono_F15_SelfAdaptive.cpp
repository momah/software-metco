/***********************************************************************************
 * AUTORES
 *   - Eduardo Manuel Segredo Gonz�lez
 *   - Carlos Segura Gonz�lez
 * 
 * FECHA
 *    Abril 2012
 ************************************************************************************/

#include "Mono_F15_SelfAdaptive.h"
#include <math.h>

double f15[1000] = {3.307860e+00,8.655789e-01,2.667253e+00,2.043353e+00,-3.042870e+00,-1.125220e+00,-6.827842e-01,-8.244109e-02,-2.399951e+00,6.741291e-01,1.958678e+00,-3.222226e-01,-1.076090e+00,4.429978e+00,-4.193992e+00,-2.317811e+00,-2.026491e+00,1.345142e+00,-3.357466e+00,3.111866e-01,-4.275712e+00,3.476580e+00,-4.022233e+00,4.238717e-01,-3.508876e+00,-2.296341e+00,-3.878569e+00,-3.878022e+00,4.371829e+00,4.837989e+00,-1.059284e+00,3.764483e+00,4.513140e+00,-1.879591e+00,-4.894156e-01,2.319688e+00,-2.061433e+00,-1.011596e+00,1.797843e+00,2.057624e+00,-4.802948e+00,4.018816e+00,4.982634e+00,1.317671e-01,8.333112e-01,-4.539624e+00,-3.492238e+00,-3.570582e+00,-4.977606e+00,-3.902594e-01,
-4.193404e+00,-3.402472e-01,-2.000987e+00,4.577158e+00,9.801478e-02,-4.138616e+00,9.833899e-01,-3.379924e-01,4.179959e+00,-1.055838e+00,2.398284e+00,3.060334e+00,-4.837415e+00,2.124372e+00,5.532789e-01,3.988957e+00,-9.940898e-01,-3.699919e+00,4.456742e+00,-6.029551e-01,4.498687e+00,2.755961e+00,-1.666825e+00,-4.275726e+00,-4.094387e+00,-4.406771e+00,-3.283435e+00,2.194090e+00,-3.048598e+00,-3.713855e+00,2.044235e+00,-3.114926e+00,-3.444207e-01,2.100046e+00,-1.289101e-01,-4.143433e+00,-4.973894e+00,-3.822870e+00,-2.654879e-01,3.282777e+00,1.960723e+00,-4.940786e+00,1.173971e+00,-4.584356e+00,-8.325269e-01,-2.311271e+00,-3.021533e-01,2.931585e+00,2.297329e-01,-4.583740e+00,
-4.763594e+00,-3.184307e+00,4.239943e+00,-4.224607e+00,-1.670635e+00,2.571128e-01,7.865621e-01,3.764315e+00,2.967046e+00,9.282938e-01,5.801968e-01,-3.971563e+00,-2.518000e+00,7.566332e-01,-5.578726e-01,-4.973684e+00,2.322671e+00,3.023220e+00,-7.439866e-01,4.574483e+00,-2.025762e+00,-2.470509e+00,-5.214313e-01,-4.136599e+00,1.752607e+00,3.169672e+00,-7.952032e-01,4.420714e-02,-1.219824e+00,-1.608928e+00,2.528224e+00,-2.965372e-01,2.338006e+00,2.308316e+00,2.892259e+00,8.299219e-01,-1.859816e+00,1.001401e+00,-2.536613e+00,3.487294e+00,2.335555e+00,-3.436875e+00,-2.917615e-01,4.853184e+00,3.182171e-01,-1.432982e+00,-2.143966e+00,-1.073037e+00,9.260110e-01,8.275831e-01,
4.221211e-01,-2.474878e+00,-1.449676e+00,2.082287e+00,1.386891e+00,-4.727236e+00,4.028928e+00,4.526949e+00,-1.417576e+00,2.496110e+00,1.195161e+00,4.882525e+00,-1.624348e+00,-1.450628e+00,-4.860089e+00,1.536151e-01,1.755842e+00,1.469857e+00,8.140121e-01,3.107755e+00,-3.167613e+00,6.282623e-01,-2.408312e+00,-2.816743e+00,-4.349519e+00,1.940387e+00,2.441588e+00,-1.768264e+00,-1.428542e+00,-9.667379e-01,-1.536914e+00,-3.528007e+00,-1.184902e-01,1.606617e+00,4.557060e+00,-8.067155e-01,3.185596e+00,4.938560e+00,-8.135079e-01,4.275978e+00,-4.680459e+00,-2.650516e+00,-4.329155e+00,-3.647610e+00,-4.744463e+00,3.646868e+00,2.742782e+00,-7.822555e-02,2.069234e+00,-3.200413e+00,
-2.328973e+00,2.484626e+00,3.297987e+00,1.658366e+00,3.687231e+00,3.753587e+00,1.578677e+00,-9.462344e-01,-4.883982e+00,-3.450699e+00,1.533833e+00,-4.006449e+00,-2.641021e+00,-1.999657e+00,-3.063219e+00,1.022086e+00,3.119198e+00,-3.367088e+00,-1.664977e+00,2.336753e-02,-1.362998e+00,-1.543720e+00,-4.405721e+00,2.773369e+00,-2.758104e+00,1.112181e+00,-1.185043e-01,-4.564476e-01,-4.927678e+00,-3.480824e+00,-1.101789e+00,3.987893e+00,-1.264949e+00,-4.742726e+00,2.831575e+00,3.504954e+00,-9.283779e-01,4.303400e+00,3.794440e+00,-3.395210e+00,2.695473e+00,-4.013116e+00,4.740660e-01,2.728707e+00,-1.752670e-01,-2.825412e+00,4.880802e+00,1.705052e-01,6.669304e-01,-4.264003e+00,
3.605721e+00,-4.955982e+00,-4.258499e+00,-2.379798e+00,1.331543e+00,-4.651147e+00,-4.684563e+00,4.153853e+00,3.390799e+00,-5.059557e-01,-3.144379e+00,2.623879e+00,-4.445286e+00,-3.033388e+00,6.310003e-02,3.459060e+00,3.136662e+00,4.235419e+00,-4.898827e+00,-3.891187e+00,-9.687546e-01,1.793348e+00,2.188572e+00,-1.184083e+00,1.350730e+00,-2.805973e+00,3.130920e+00,-3.267119e+00,-4.464346e+00,9.855187e-01,1.322930e+00,-3.122419e+00,3.070432e+00,-2.107636e+00,7.038339e-01,4.838031e+00,3.949645e+00,2.062862e+00,3.605791e+00,-3.690340e+00,-3.365477e+00,3.387346e-01,-1.745996e+00,2.163139e+00,4.739449e+00,-4.305802e-01,-2.321648e+00,-4.904240e-01,-4.424684e+00,-2.807920e+00,
1.889297e+00,-2.172354e+00,1.517307e+00,2.755023e+00,-8.008613e-01,-3.530023e+00,3.102132e-03,-2.499121e+00,-1.526074e+00,3.608970e+00,3.315360e-01,1.220118e+00,1.664024e+00,-3.993803e+00,-2.301467e+00,-2.499835e+00,2.916894e+00,-4.616904e+00,1.276629e+00,-2.537383e+00,-2.062988e+00,-7.979412e-02,-3.535457e+00,3.633563e+00,-9.941319e-01,-2.456707e-01,2.830174e+00,2.091313e-01,2.327769e+00,-1.050937e+00,-3.219404e+00,2.994860e+00,2.722384e-01,-8.709009e-01,2.786618e+00,-2.596065e+00,-2.251581e+00,-1.686005e-01,-5.927594e-01,-3.396149e+00,-4.623641e+00,1.891579e+00,-2.936165e+00,-4.630419e+00,-5.148909e-01,4.852540e+00,1.442043e+00,-3.297665e+00,-1.917951e+00,1.288120e-01,
-1.673800e+00,-8.708729e-01,-2.470817e+00,-3.195119e+00,-1.464998e+00,1.960471e+00,4.477441e+00,-4.615735e-01,-2.296061e+00,2.976016e-01,2.474682e+00,-3.999027e+00,-1.535345e+00,1.589965e+00,-3.710864e-01,-1.627065e+00,-1.968061e+00,-8.271769e-01,-1.258576e+00,-3.453331e+00,3.881678e+00,-3.055572e+00,-1.541550e+00,1.619950e+00,1.047841e+00,1.494647e+00,1.143020e+00,4.289423e+00,-3.174000e+00,-4.380344e+00,-4.418074e+00,-4.316901e+00,5.041350e-01,3.309247e+00,4.442821e+00,4.437233e+00,-3.235650e+00,-1.454326e+00,3.563552e+00,9.441196e-01,1.527082e+00,-3.469766e-02,5.606176e-01,4.933091e-01,-7.459333e-01,-1.009173e+00,2.490060e+00,2.518686e+00,3.581310e+00,3.096145e+00,
1.356374e+00,-1.199601e+00,-2.550086e+00,-1.754623e+00,3.794874e+00,1.429887e+00,3.588817e+00,9.829838e-01,3.643101e+00,-1.886426e+00,3.730605e+00,3.586296e+00,-3.296768e+00,-1.521186e+00,9.860789e-01,2.559224e-01,8.890235e-01,-3.552586e+00,4.856392e+00,4.739407e+00,1.918441e+00,4.924835e+00,7.273555e-02,-2.810455e+00,2.269038e-01,3.083372e+00,-1.309268e-01,3.014453e+00,-4.073674e+00,1.891916e+00,3.772200e+00,-6.526872e-01,-4.694899e+00,-1.375652e-01,3.045194e+00,-4.205028e+00,1.751388e+00,-1.085193e+00,1.200413e+00,1.010714e+00,4.726186e+00,-4.402766e+00,-4.238360e+00,-3.364161e+00,3.696040e+00,-8.600469e-01,8.933651e-01,-1.000042e+00,4.829040e+00,-6.306852e-01,
7.346311e-01,-1.885557e+00,3.727692e+00,-3.615910e-01,-2.837926e-01,2.328889e+00,1.519310e+00,4.281160e+00,-1.770547e+00,-2.128672e+00,-3.687763e+00,-8.592136e-03,-4.822737e+00,-4.442737e+00,-1.268233e-01,3.152236e+00,-1.901201e+00,1.874717e+00,-2.332951e+00,6.938062e-01,1.438332e+00,-4.457540e+00,2.898323e+00,2.580365e+00,-1.907853e+00,-7.073352e-01,-4.884542e+00,4.352698e+00,-3.919352e+00,2.547271e+00,-8.488848e-01,3.179938e+00,-3.249389e+00,4.062792e+00,2.210420e+00,9.112776e-01,9.080845e-01,-5.935997e-01,4.241819e+00,4.227982e+00,-2.810161e+00,-3.364553e+00,-2.911768e+00,-6.178355e-02,-3.777718e+00,7.582858e-01,3.274486e+00,9.733903e-01,-3.743924e+00,-4.153846e-01,
3.709709e+00,-2.022989e+00,1.453808e+00,6.134939e-02,1.412535e+00,2.509065e+00,-8.170792e-01,-3.403655e+00,-3.086804e+00,1.884241e+00,-3.183173e+00,3.213816e+00,-2.279969e+00,4.542593e+00,3.870544e+00,-4.096068e+00,2.709044e+00,-2.455551e+00,-2.102118e+00,-8.389762e-02,3.914324e+00,1.808270e-01,1.133735e+00,-5.628724e-01,-1.619600e+00,-5.474528e-01,-3.148874e+00,-9.402262e-01,-3.314933e+00,2.675305e+00,-1.002843e+00,-2.443423e+00,-2.770372e+00,-2.467204e+00,-4.784783e+00,6.193551e-01,-3.154827e+00,4.275894e+00,-1.566311e+00,-3.113021e+00,4.092329e+00,9.883898e-01,-3.258128e+00,3.275200e+00,6.381359e-01,3.041777e+00,3.067000e+00,-1.429145e+00,-2.814068e+00,1.099030e+00,
1.368769e+00,-1.732775e+00,3.278982e+00,-2.300095e+00,3.081384e+00,4.901642e+00,-3.884115e+00,3.062673e+00,4.195182e+00,-3.724050e+00,-2.683905e+00,4.687420e+00,-4.081580e-01,8.994993e-01,-1.193116e+00,1.419348e-01,4.495746e+00,-3.716642e+00,-1.046651e+00,3.695536e+00,-4.170715e+00,4.122902e+00,3.325661e+00,2.876349e+00,-9.648332e-01,-2.015987e+00,2.784811e+00,1.977403e+00,2.934848e+00,-4.420363e-01,-4.544050e+00,1.557039e+00,1.412128e+00,-1.697819e+00,-4.249130e+00,3.872602e+00,-5.863870e-01,2.913672e+00,1.630650e+00,4.097020e+00,-3.870110e+00,-7.572634e-01,2.002038e+00,-2.932271e+00,5.393859e-01,-1.831624e+00,-1.552194e+00,6.053710e-02,3.484269e+00,7.025034e-01,
-3.854137e-01,4.581373e+00,-3.375659e+00,-2.022709e+00,3.401148e+00,-2.746367e+00,2.253247e+00,2.341340e+00,-2.383383e+00,-1.100907e+00,-2.483197e+00,-1.611603e+00,3.214523e-01,2.295319e+00,-3.503316e+00,1.055824e+00,-3.403942e-02,-3.021673e-01,4.575771e+00,1.906929e+00,-2.765779e+00,3.110822e+00,2.691411e+00,1.037030e+00,-2.265880e+00,-3.794230e+00,4.079430e+00,3.760884e+00,-1.675971e+00,5.447918e-01,4.313315e+00,-1.891691e+00,-8.980008e-01,3.291572e+00,5.435174e-01,1.949112e+00,7.686706e-02,3.842772e+00,3.027975e-01,1.298883e+00,4.339491e+00,-3.992087e-01,4.483744e+00,-2.784699e+00,-3.606940e+00,2.024684e+00,3.201478e+00,2.764252e+00,3.081958e+00,3.381534e-02,
1.921074e+00,-3.956927e+00,4.480382e+00,-4.843878e-01,2.801730e+00,1.119478e+00,-4.950786e+00,2.536921e+00,7.243654e-01,-3.486552e+00,2.467512e+00,-2.107132e+00,-5.685025e-01,-7.335247e-01,-2.684507e+00,-2.612086e+00,9.961626e-01,1.709499e+00,1.669402e+00,-1.115192e+00,-1.894661e+00,1.794118e+00,-3.857869e+00,3.622779e+00,2.289129e+00,1.387521e+00,-2.189538e+00,-3.797605e+00,1.014089e+00,9.445748e-02,1.950555e+00,-1.607780e+00,1.028430e+00,-1.016666e+00,2.387416e+00,1.583957e+00,4.581135e+00,3.683239e+00,5.665558e-01,-3.192584e+00,2.180939e+00,-3.907545e+00,8.859564e-01,-5.850635e-02,1.165666e+00,4.620574e+00,-9.968208e-01,-3.777529e-01,1.861202e+00,-1.581786e+00,
4.441651e-01,2.306999e+00,-5.118658e-01,-6.199713e-01,-4.951948e+00,-1.183369e+00,-2.677567e-01,1.300564e+00,-2.095508e+00,4.134652e+00,-4.170239e+00,-2.262799e+00,2.288806e+00,-3.767242e+00,-1.697020e+00,-2.554119e+00,4.387248e+00,-2.670376e+00,-4.174763e+00,2.945842e+00,-3.151101e+00,4.085802e+00,-1.232919e+00,-2.806463e+00,-4.560520e+00,-4.730990e+00,-4.336802e+00,-2.486545e+00,-9.930955e-01,-4.574567e+00,-3.749498e+00,-4.037135e+00,-2.361269e+00,7.986765e-01,2.503309e+00,2.970001e+00,-4.834474e+00,1.896775e+00,3.555373e+00,-3.660761e+00,2.752292e+00,2.324358e-01,-3.891467e+00,1.117881e+00,-4.833773e+00,4.942747e+00,-2.267841e+00,1.133707e+00,-4.959315e+00,7.908897e-01,
3.558034e+00,2.358986e+00,1.102784e+00,3.533609e+00,2.380834e+00,-2.999412e+00,3.331781e+00,-1.259375e+00,-3.528098e-01,-8.980148e-01,-2.121795e+00,4.649480e+00,4.178852e+00,3.581142e+00,-9.005217e-01,-3.155121e+00,3.222303e+00,-1.373348e+00,3.313686e+00,4.867540e+00,-6.023949e-01,-4.126151e+00,-1.663212e+00,1.704583e+00,1.488946e+00,4.943783e+00,-9.200658e-02,5.769056e-01,-4.815917e+00,2.688722e+00,3.304975e+00,-3.275901e+00,6.153636e-01,-1.144519e+00,-2.531487e+00,-4.426169e+00,9.164875e-01,4.138700e+00,-1.220693e+00,-3.827618e+00,7.793495e-01,2.248892e+00,-4.243290e+00,-3.782900e+00,4.911404e+00,-5.234341e-01,1.060586e+00,-1.813683e+00,1.357522e+00,4.250341e-01,
2.810483e+00,-4.736382e+00,-4.700459e+00,-3.141914e+00,-1.931095e-01,3.637037e+00,-3.168341e+00,-1.960569e+00,-2.463478e+00,4.714870e+00,-3.489927e+00,-3.948860e+00,3.768615e+00,1.571283e+00,3.515500e+00,3.350828e+00,5.387977e-01,-1.700606e+00,-2.040055e-01,-2.361661e+00,-1.232471e+00,-6.019047e-01,-2.805497e+00,-4.824936e+00,3.700606e+00,2.380078e+00,4.344337e+00,-3.795939e+00,9.609958e-01,-2.796478e+00,-3.332397e+00,-4.904660e-01,-4.211267e-01,-1.744918e+00,4.857806e+00,2.232856e+00,-3.099758e+00,8.642204e-01,-3.909380e+00,3.880109e+00,-3.278527e-01,-1.413081e+00,2.756325e+00,3.235538e+00,-1.023501e+00,-2.374462e+00,3.064410e+00,-3.680368e+00,-6.675326e-01,-2.921263e+00,
2.113616e+00,-1.680816e+00,-4.085102e+00,4.804307e+00,2.136361e+00,-4.189622e+00,2.843227e+00,-4.881573e+00,-4.941529e+00,4.022793e+00,1.580512e+00,-3.115122e+00,-1.031834e+00,1.038220e+00,1.854130e+00,-1.094240e+00,-4.244914e+00,-4.656763e+00,2.716887e+00,2.140632e+00,2.033843e+00,4.876657e+00,2.082665e+00,-4.633514e+00,7.371591e-02,-1.652652e+00,4.089276e+00,-2.875340e+00,4.163230e-01,3.503750e+00,1.856539e+00,-1.918189e+00,-2.304212e+00,1.432226e+00,-1.447757e+00,1.532432e+00,4.866993e+00,-2.267225e+00,3.746157e-01,-1.791499e+00,-3.964112e+00,-2.364798e+00,-4.678331e+00,2.540002e+00,6.312594e-01,-2.863366e+00,-3.871923e-01,-4.576191e+00,3.598564e+00,1.084283e+00,
-8.328140e-02,2.102300e+00,8.449984e-02,-3.243913e+00,-1.756528e+00,-4.413200e+00,2.855712e-01,3.485137e+00,-7.427611e-02,2.031098e+00,1.593565e+00,3.177627e+00,-4.916600e+00,2.757992e+00,4.157908e-01,-8.438080e-03,-2.699275e-01,4.468828e+00,9.669759e-01,-1.430517e+00,2.460208e-01,-2.784293e+00,3.026806e+00,-1.934239e+00,-2.186485e+00,-2.781548e+00,3.511985e+00,4.376387e-01,7.340289e-01,-5.864290e-01,1.634922e+00,-2.736004e+00,-1.383348e+00,-9.885718e-01,-5.970589e-01,1.121410e+00,5.014040e-01,3.176282e+00,1.979265e+00,-4.097125e-01,-1.514023e-01,4.927734e+00,-1.665698e-01,-3.136200e+00,-4.573726e+00,2.977277e-01,-5.758972e-01,-3.653023e-01,-3.517923e+00,-1.312762e+00,
3.350002e+00,1.216981e+00,-4.934386e+00,7.897973e-01,-2.371507e+00,-2.911390e+00,3.881944e+00,-3.201057e+00,-4.709814e+00,-4.741031e+00,-2.570253e+00,-1.439845e+00,-2.382178e+00,2.650068e+00,-2.190855e+00,-2.312223e+00,-4.375638e+00,-3.713322e+00,4.732446e+00,-4.508365e+00,-3.543552e+00,-7.256399e-01,2.751619e+00,-4.023704e+00,-3.256476e+00,1.729918e+00,-1.558244e+00,3.752341e+00,-3.014929e+00,1.477126e+00,-1.161689e+00,-3.133147e+00,-2.006337e+00,3.016526e+00,4.484556e+00,-7.135675e-01,-4.222688e+00,-2.765036e+00,-3.926620e+00,-1.317734e+00,-4.110829e+00,3.063667e+00,-3.486370e+00,-1.620321e-01,3.447148e-01,-3.379356e+00,1.978271e+00,3.981968e+00,4.529834e+00,1.663338e+00};

double Mono_F15_SelfAdaptive::getMaximum (const int i) const {
  if (i == getNumberOfVar() - 1) {
    return 1;
  }
  return 10;
}

double Mono_F15_SelfAdaptive::getMinimum (const int i) const {
  if (i == getNumberOfVar() - 1) {
    return 0;
  }
  return -10;
}

bool Mono_F15_SelfAdaptive::init (const vector<string> &params){

  if ((params.size() > 2) || (params.size() < 1)){
    cerr << "Error in init -> Parameters: Number of variables [mns parameter]" << endl;
    exit(-1);
  }
  
  if (params.size() == 1) {
    setMns(0.25);
  }
  else {
    setMns(atof(params[1].c_str()));
  }
 
  setNumberOfVar(atoi(params[0].c_str()) + 1);
	setNumberOfObj(NOBJ);
	return true;
}

// Evaluacion
void Mono_F15_SelfAdaptive::divideFunctions(double *s, double *part1, double *part2, int *psize1, int *psize2) {
  int shared;
  int rest, i, total;
  double *partrest;

  if (getMns() <= 0.5) {
    partrest = part2;
  }
  else {
    partrest = part1;
    setMns(1 - getMns());
  }

  shared = (int) floor((getNumberOfVar() - 1) * getMns());
  rest = 2 * shared;

  for (i = 0; i < shared; i++) {
    part1[i] = s[i * 2];
    part2[i] = s[i * 2 + 1];
  }
  
  total = (getNumberOfVar() - 1) - shared;

  for (i = 0; i < total - shared; i++) {
    partrest[i + shared] = s[i + rest];
  }

  *psize1 = shared;
  *psize2 = (getNumberOfVar() - 1) - shared;

  if (partrest == part1) {
    int temp = *psize1;
    *psize1 = *psize2;
    *psize2 = temp;
  }
}

long double Mono_F15_SelfAdaptive::f_BohachevskyNoDesplazamiento(int dim, double *s) {
  long double currentGen = s[0];
  long double sum = 0.0;
  long double nextGen;

  for (int i = 1; i < dim; i++) {
    nextGen = s[i];
    sum += currentGen * currentGen + 2.0 * nextGen * nextGen;
    double c1 = cos(3.0 * M_PI * currentGen);
    double c2 = cos(4.0 * M_PI * nextGen);
    sum += 0.7 - (0.3 * c1 + 0.4 *c2);
    currentGen = nextGen;
  }

  return sum;
}

long double Mono_F15_SelfAdaptive::f_Schwefel2_22NoDesplazamiento(int dim, double *s) {
  long double sum = 0.0;
  long double prod = 1.0;
  long double currentGen;

  for (int i = 0; i < dim; i++) {
    currentGen = fabs(s[i]);
    sum += currentGen;
    prod *= currentGen;
  }

  return sum + prod;
}

void Mono_F15_SelfAdaptive::evaluate (void) {
  double part1[getNumberOfVar() - 1], part2[getNumberOfVar() - 1], desp[getNumberOfVar() - 1];
  int size1, size2;
  long double f1, f2;

  for (int i = 0; i < getNumberOfVar() - 1; ++i) {
    desp[i] = getVar(i) - f15[i];
  }

  divideFunctions(desp, part1, part2, &size1, &size2);

  f1 = f_BohachevskyNoDesplazamiento(size1, part1);
  f2 = f_Schwefel2_22NoDesplazamiento(size2, part2);

  setObj(0, f1 + f2);
}

// Clonacion
Individual* Mono_F15_SelfAdaptive::clone (void) const{
  Individual *ind = new Mono_F15_SelfAdaptive();
  ((Mono_F15_SelfAdaptive*)ind)->setMns(getMns());
  return ind;
}